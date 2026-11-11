#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5;
int c, n, m, D, q, w[N], a[N];
ll g[605][605], t[N], d[N];
vector<int> e[N];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    if(12<=c&&c<=19)
    {
        ll tmp=0;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                cin>>a[j]>>t[j];
                tmp=t[j];
            }
            for(int j=1;j<=k;j++)
            {
                for(int l=j+1;l<=k;l++)
                {
                    e[a[j]].push_back(a[l]);
                    e[a[l]].push_back(a[j]);
                }
            }
        }
        while(q--)
        {
            int u, v;
            cin>>u>>v;
            for(int i=1;i<=m;i++) d[i]=LONG_MAX;
            queue<int> q;
            q.push(u);
            d[u]=0;
            while(q.size())
            {
                int u=q.front();q.pop();
                for(int v : e[u])
                {
                    if(d[v]>d[u]+2ll*tmp)
                    {
                        d[v]=d[u]+2ll*tmp;
                        q.push(v);
                    }
                }
            }
            cout<<d[v]+w[u]+w[v]<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            g[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)
    {
        g[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;j++)
        {
            for(int l=j+1;l<=k;l++)
            {
                g[a[l]][a[j]]=g[a[j]][a[l]]=min(g[a[j]][a[l]], t[j]+t[l]);
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                g[i][j]=min(g[i][j], g[i][k]+g[j][k]);
            }
        }
    }
    while(q--)
    {
        int u, v;
        cin>>u>>v;
        cout<<g[u][v]+w[u]+w[v]<<"\n";
    }
    return 0;
}
