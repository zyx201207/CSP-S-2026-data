#include<bits/stdc++.h>
using namespace std;
struct Node
{
    long long k;
    vector<long long> x;
    vector<long long> t;
}a[1010];
long long w[1000010];
vector<pair<long long,long long> > adj[1000010];
vector<pair<long long,long long> > ques[1000010];
long long ans[1000010];
long long dist[1000010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,m,n,d,q;
    cin>>c>>m>>n>>d>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(long long i=1;i<=m;i++)
    {
        cin>>a[i].k;
        for(long long j=1;j<=a[i].k;j++)
        {
            long long q,w;
            cin>>q>>w;
            a[i].x.push_back(q);
            a[i].t.push_back(w);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        for(long long j=1;j<a[i].k;j++)
        {
            for(long long k=0;k<j;k++)
            {
                adj[a[i].x[k]].push_back({a[i].x[j],a[i].t[j]+a[i].t[k]});
                adj[a[i].x[j]].push_back({a[i].x[k],a[i].t[j]+a[i].t[k]});
            }
        }
    }
    //cout<<w[123]<<' '<<w[131]<<'\n';
    //for(int i=1;i<=n;i++)
    //{
        //cout<<i<<'\n';
        //for(auto x:adj[i])
        //{
            //cout<<x.first<<' '<<x.second<<'\n';
        //}
        //cout<<'\n';
    //}
    for(long long i=1;i<=q;i++)
    {
        long long u,v;
        cin>>u>>v;
        ques[u].push_back({i,v});
    }
    for(long long i=1;i<=n;i++)
    {
        if(ques[i].size()==0)
        {
            continue;
        }
        for(long long j=1;j<=n;j++)
        {
            dist[j]=1e18;
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
        q.push({0,i});
        dist[i]=0;
        while(!q.empty())
        {
            pair<long long,long long> tp=q.top();
            q.pop();
            long long x=tp.first;
            long long y=tp.second;
            //cout<<y<<'\n';
            if(dist[y]!=x)
            {
                continue;
            }
            for(auto u:adj[y])
            {
                if(dist[y]+u.second<dist[u.first])
                {
                    dist[u.first]=dist[y]+u.second;
                    q.push({dist[u.first],u.first});
                }
            }
        }
        //for(int i=1;i<=n;i++)
        //{
            //cout<<dist[i]<<' ';
        //}
        //cout<<'\n';
        //if(i==123)
        //{
            //cout<<dist[131]<<'\n';
        //}
        for(long long j=0;j<ques[i].size();j++)
        {
            //cout<<ques[i][j].first<<'\n';
            ans[ques[i][j].first]=dist[ques[i][j].second]+w[i]+w[ques[i][j].second];
        }
    }
    for(long long i=1;i<=q;i++)
    {
        cout<<ans[i]<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
