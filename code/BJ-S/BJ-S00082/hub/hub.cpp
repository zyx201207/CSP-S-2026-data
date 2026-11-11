#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,f[1000010],m;
vector<int> e[1000010];
void dfs(int x,int fa)
{
    f[x] = f[fa] + 1;
    if(f[x] > f[m]) m = x;
    for(int i = 0;i < e[x].size();i++) if(e[x][i] != fa) dfs(e[x][i],x);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        m = 0;
        cin >> n >> k;
        for(int i = 1,u,v;i <= n;i++) cin >> u >> v,e[u].push_back(v),e[v].push_back(u);
        dfs(1,0);
        dfs(m,0);
        cout << min(f[m],k) << endl;
    }
    return 0;
}
