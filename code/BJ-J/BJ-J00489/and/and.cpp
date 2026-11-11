#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    long long a[200000], t = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) for (int j = 1; j < m; j++) t = max(t, a[i] & a[i + j]);
    cout << t;
    return 0;
}