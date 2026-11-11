#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=2e6+5;
using ll=long long;
int c,n,m,d,Q;
vector<ll> w;
//the index of the j-th platform of the i-th station is idx(i)+j
//idx(i) is the real index of the i-th station(the index in the code)
//IDX(i) is the virtual index of the i-th station(the index in the question)
unordered_map<int,int> mp;//record the real index of the station
vector<vector<pair<int,ll> > > e;//graph

vector<ll> dist;
bool vis[M];
void dijkstra(int S,int T)
{
    dist.resize(m*(d+1)+5,1e18);memset(vis,false,sizeof vis);
    priority_queue <pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
    
    dist[mp[S]]=0;
    q.push({0,mp[S]});
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto edge:e[u])
        {
            int v=edge.first;
            ll w=edge.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }

    cout<<w[S]+dist[mp[T]]+w[T]<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>Q;

    //build the graph
    w.resize(m+5);e.resize(m*(d+1)+5);
    for(int i=1;i<=m;i++)mp[i]=(d+1)*(i-1)+1;//idx(i)
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int K;cin>>K;
        int lst;//IDX(last station)
        for(int j=1;j<=K;j++)
        {
            int cur;ll t;
            cin>>cur>>t;
            
            e[mp[cur]].push_back({mp[cur]+i,t});
            e[mp[cur]+i].push_back({mp[cur],t});

            if(j>1)
            {
                e[mp[lst]+i].push_back({mp[cur]+i,0});
                e[mp[cur]+i].push_back({mp[lst]+i,0});
            }
            lst=cur;
        }
    }
    while(Q--)
    {
        int u,v;
        cin>>u>>v;
        dijkstra(u,v);
    }
    return 0;
}
/*
cd subway
ulimit -s unlimited
g++ subway.cpp -o subway -O2 -std=c++14 -static -Wall
time ./subway
*/