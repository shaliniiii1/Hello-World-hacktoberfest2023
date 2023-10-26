#include <iostream>
#include <vector>

void countingSort(std::vector<int> &arr) {
    // Find the maximum value in the input array
    int max = *std::max_element(arr.begin(), arr.end());

    // Create a counting array with a size of (max + 1) and initialize it with zeros
    std::vector<int> count(max + 1, 0);

    // Count the occurrences of each element in the input array
    for (int element : arr) {
        count[element]++;
    }

    // Reconstruct the sorted output array using the counting array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    std::cout << "Original array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}
