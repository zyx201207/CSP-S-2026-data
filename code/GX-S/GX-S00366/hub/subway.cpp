#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const long long inf=1e18;

struct Edge{
    int to;
    long long weight;
};

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c,n,m,d,q;
   cin>>c>>n>>m>>d>>q;
        vector<long long> w(m+1);
        for(int i=1;i<=m;i++)
        {
            cin>>w[i];
        }
        vector<vector<Edge>> adj(m+n+1);
        for(int i=1;i<=n;i++){
            int k;cin>>k;
            int line_node=m+i;
            for(int j=0;j<k;j++)
            {
                int station; long long t;
                cin>>station>>t;
                adj[station].push_back({line_node,t});
                adj[line_node].push_back({station,t});
            }
        }
        vector<vector<long long>> all_dist(m+1,vector<long long>(m+1,inf));
        for(int start=1;start<=m;start++)
        {
            vector<long long> dist(m+n+1,inf);
             priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

             dist[start]=0;
             pq.push({0,start});

             while(!pq.empty()){
                pair<long long ,int> top=pq.top();
                pq.pop();
                long long d=top.first;
                int u=top.second;

                if(d>dist[u]) continue;

                for(size_t j=0;j<adj[u].size();j++){
                    int v=adj[u][j].to;
                    long long w=adj[u][j].weight;
                    if(dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                        pq.push({dist[v],v});
                    }

                }
            }
            for(int end=1;end<=m;end++)
            {
                all_dist[start][end]=dist[end];
            }

        }
     for(int i=0;i<q;i++){
        int x,y;cin>>x>>y;
        if(x==y){
            cout<<w[x]+w[y]<<endl;
        }
        else{
             cout<<w[x]+all_dist[x][y]+w[y]<<endl;
        }

    }
     return 0;
}
