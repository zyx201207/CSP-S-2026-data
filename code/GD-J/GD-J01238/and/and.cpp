#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m, k = 1, ans, a[200005];
vector<int> v;
bool cmp(int u, int v) { return u > v; }
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, cmp);
    ans = a[1];
    for (int i = 2; i <= m; i++)
        ans = ans & a[i], k++;
    cout << ans << endl;
    return 0;
}