#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// bitset<32> bs[200005];

// void quick_sort(bitset<32> list[], int start, int ends) {
//     if ()
// }

int nums[200005];

int main() {
    freopen("./and.in", "r", stdin);
    freopen("./and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        // int a;
        // cin >> a;
        // bs[i] = bitset<32>(a);
        cin >> nums[i];
    }
    sort(nums, nums + n, greater<int>());
    int res = nums[0];
    for (int i = 1; i < m; i++) {
        if (nums[i] == nums[i - 1] || ) {
            m++;
            continue;
        }
        res &= nums[i];
    }
    cout << res << endl;
    return 0;
}
