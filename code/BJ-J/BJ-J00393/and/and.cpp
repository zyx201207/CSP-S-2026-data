#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans = -1,s = 1,c;
bool f[200005];
void dfs(long long x)
{
    if(x == m+1)
    {
        ans = max(ans,s);
        s = c;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(f[i] == 0)
        {
            f[i] = 1;
            if(x == 1)
            {
                s = a[i];
                c = a[i];
            }
            else
                s &= a[i];
            dfs(x+1);
            f[i] = 0;
        }
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    dfs(1);
    cout << ans;
}
