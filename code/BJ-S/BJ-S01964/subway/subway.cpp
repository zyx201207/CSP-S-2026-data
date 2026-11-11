#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005],k[20005],v[20005];
int t;
vector<int>a[20005],b[20005];
int ans = INT_MAX;
void dfs(int x,int y,int h)
{
    if(x == y)
    {
        if(h <ans)
            ans = h;
        return;
    }
    if(ans <= h)
        return;
    for(auto i : a[x])
    {
        for(auto j :b[i])
        {
            if(v[j] == 1)
                dfs(a[x][j],y,h);
            else
                dfs(a[x][j],y,h + t);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            int aa;
            cin >>aa >>t;
            a[aa].push_back(i);
            b[i].push_back(aa);
        }
    }
    int x,y;
    for(int r = 1;r <= q;r++)
    {
        cin >> x >> y;
        for(auto i :a[x])
            v[i] = 1;
        dfs(x,y,0);
        cout << ans + w[x] + w[y]<< endl;
    }
    return 0;
}
