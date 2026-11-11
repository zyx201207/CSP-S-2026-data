#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,Q,ans,w[50005],k[505],a[505][50005],t[505][50005],f[505][50005];
struct dat{int x,c,d,idx;};
struct node{int c,x;};
vector<node> g[505][50005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int i,j,x,y,u,v,c,cc;
    cin>>c>>n>>m>>d>>Q;
    for(i=1;i<=m;i++)
        cin>>w[i];
    for (i=1;i<=n;i++)
    {
        cin>>k[i];
        for (j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
        }
        for (j=1;j<=k[i];j++)
            for(x=j+1;x<=k[i];x++)
            {
                g[i][a[i][j]].push_back({i,a[i][x]});
                g[i][a[i][x]].push_back({i,a[i][j]});
            }
    }
    for(i=1;i<=m;i++)
        for(j=1;j<n;j++)
            for(x=j+1;x<=n;x++)
                if(t[j][i]&&t[x][i])
                {
                    g[j][i].push_back({x,i});
                    g[x][i].push_back({j,i});
                }
    while (Q--)
    {
        queue<node>q;
        cin>>x>>y;
        memset(f,0x3f,sizeof f);
        for(i=1;i<=n;i++)
            if(t[i][x])
            {
                q.push({i,x});
                f[i][x]=t[i][x];
            }
        while(!q.empty())
        {
            u=q.front().x,c=q.front().c;
            q.pop();
            for(node e:g[c][u])
            {
                v=e.x,cc=e.c;
                if(f[c][u]+t[cc][v]<f[cc][v])
                {
                    f[cc][v]=f[c][u]+t[cc][v];
                    q.push(node{cc,v});
                }
            }
        }
        for(ans=1e9,i=1;i<=n;i++)
            if(t[i][y])
                ans=min(ans,f[i][y]);
        cout<<w[x]+w[y]+ans<<endl;
    }
    /*
    while (q--)
    {
        cin>>x>>y;
        ans=0;
        queue<dat>q;
        q.push(dat{x,0,w[x]+w[y],0});
        while (!q.empty())
        {
            dat p=q.front();
            u=p.x,c=p.c,d=p.d,idx=p.idx;
            vis[u]=1;
            cout<<u<<" "<<c<<" "<<d<<endl;
            q.pop();
            for(i=1;i<=n;i++)
            {
                if(i==c||!is[i][u])
                    continue;
                for (j=1;j<=k[i];j++)
                {
                    if(j==u)
                        continue;
                    if(!vis[u])
                        q.push(dat{a[i][j],i,d+t[c][idx]+t[i][j],j});
                }
            }
        }
        cout<<ans<<endl;
    }*/
}
