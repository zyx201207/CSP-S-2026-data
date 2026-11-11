#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,w[5234567],d[5234567],f[5234567];
vector<pair<int,int>> e[5234567];
int dji(int s,int t)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(d,0x3f,sizeof(d));
    memset(f,0,sizeof(f));
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int len=pq.top().first,u=pq.top().second;
        pq.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int vl=e[u][i].first,v=e[u][i].second;
            if(!f[v])
            {
                pq.push({vl,v});
                f[v]=1;
            }
            d[v]=min(d[v],d[u]+vl);
        }
    }
    return d[t];

    return 0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)
        cin>>w[i];

    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            e[a].push_back({t,i+m+n});
            e[i+m+n].push_back({t,a});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dji(x,y)+w[x]+w[y]<<endl;
    }
	return 0;
}
