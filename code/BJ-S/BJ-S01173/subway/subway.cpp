#include<bits/stdc++.h>
using namespace std;
const int N=500,M=500000;
const long long INF=1e18;
int c,n,m,d,q,w[M+10];
long long dis[N+10][N+10];
struct node{
    int x,t;
};
vector<node> a[M+10];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=dis[j][i]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            for(auto pre:a[x]){
                dis[pre.x][i]=min(dis[pre.x][i],(long long)t+pre.t);
                dis[i][pre.x]=dis[pre.x][i];
            }
            a[x].push_back({i,t});
        }
    }
    //floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    //
    while(q--){
        int u,v;
        long long ans=INF;
        cin>>u>>v;
        for(auto x:a[u]){
            for(auto y:a[v]){
                ans=min(ans,dis[x.x][y.x]+x.t+y.t);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
//g++ subway.cpp -o b -g -std=c++14 -static -O2 -Wall -Wextra