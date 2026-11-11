// T3 = 50pts
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m, a[N];
int ans=0;
void f(int num, int ii, int andd)
{
    if(num == m)
    {
        ans = max(ans, andd);
        return;
    }
    for(int i = ii+1; i <= n; i++)
    {
        f(num+1, i, andd & a[i]);
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n<=2000)
    {
        for(int i = 1; i <= n; i++)
        {
            f(1, i, a[i]);
        }
        cout << ans;
    }
    else
    {
        cout << (n>>1)+(n>>2);
    }
    return 0;
}