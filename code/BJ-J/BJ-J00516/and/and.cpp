#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("and.in", r, stdin);
    freopen("and.out", w, stdout);
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[m - 1];
    return 0;
}
