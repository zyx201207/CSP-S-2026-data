#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
int c,n,m,d,q;
ll w[N],ds[N*2];
vector<pair<int,int>>g[N*2];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int t=m;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int p=-1;
        for(int j=1;j<=k;j++)
        {
            int a,b;
            cin>>a>>b;
            t++;
            g[a].push_back({t,b});
            g[t].push_back({a,b});
            if(p!=1)
            {
                g[p].push_back({t,0});
                g[t].push_back({p,0});
            }
            p=t;
        }
    }
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<w[x]*2<<"\n";
            continue;
        }
        for(int j=1;j<=t;j++)
        {
            ds[j]=1e18;
        }
        ds[x]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,x});
        while(!pq.empty())
        {
            ll pw=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(pw>ds[u])
            {
                continue;
            }
            if(u==y)
            {
                break;
            }
            for(int j=0;j<g[u].size();j++)
            {
                int v=g[u][j].first;
                int wt=g[u][j].second;
                if(ds[v]>ds[u]+wt)
                {
                    ds[v]=ds[u]+wt;
                    pq.push({ds[v],v});
                }
            }
        }
        cout<<w[x]+ds[y]+w[y]<<"\n";
    }
    return 0;
}
