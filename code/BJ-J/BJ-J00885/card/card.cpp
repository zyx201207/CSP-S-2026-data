#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> c; int a[n], ans[m] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        c.resize(0);
        for (int j = i; j < n; j++) {
            if (find(c.begin(), c.end(), a[j]) == c.end()) c.push_back(a[j]);
            else c = vector<int>(c.begin(), find(c.begin(), c.end(), a[j])), c.push_back(a[j]);
        }
        for (int j : c) ans[j]++;
    }
    for (int i : ans) cout << i << " ";
}
