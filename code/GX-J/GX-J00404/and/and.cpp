#include <bits/stdc++.h>
using namespace std;
int a[200005],vis[200005];
int m,n,maxs = -1;
void dfs(int pts,int sum,int chose)
{
    if(chose > m) return;
    if(chose + n - pts < m) return;
    if(chose == m)
    {
        maxs = max(maxs,sum);
        return;
    }
    vis[pts + 1] = 1;
    dfs(pts + 1,sum & a[pts + 1],chose + 1);
    vis[pts + 1] = 0;
    dfs(pts + 1,sum,chose);
}
int main()
{
    freopen("and5.in","r",stdin);
    freopen("and5.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    if(m == 1)
    {
        cout << a[n];
        return 0;
    }
    dfs(0,pow(2,31) - 1,0);
    cout << maxs;
    return 0;
}
