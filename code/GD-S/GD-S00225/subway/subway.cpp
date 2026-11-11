#include<bits/stdc++.h>
#define N 502
#define M 500005
using namespace std;
int c,n,m,d,q;
vector<pair<int,long long>>g[M];
long long dis[N][N];
long long w[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int p,t;
            cin>>p>>t;
            g[p].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dis[i][j]=0x3f3f3f3f3f3f3f3f;
            else dis[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto pq1:g[i]){
            for(auto pq2:g[i]){
                dis[pq1.first][pq2.first]=min(dis[pq1.first][pq2.first],pq1.second+pq2.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        long long res=0x3f3f3f3f3f3f3f3f;
        for(auto pq1:g[u]){
            for(auto pq2:g[v]){
                res=min(res,pq1.second+pq2.second+dis[pq1.first][pq2.first]);
            }
        }
        res+=w[u];
        res+=w[v];
        cout<<res<<"\n";
    }
}