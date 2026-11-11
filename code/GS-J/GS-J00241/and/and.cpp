#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
unsigned long long n, m, ans, a[N];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    cout << ans;
    return 0;
}
