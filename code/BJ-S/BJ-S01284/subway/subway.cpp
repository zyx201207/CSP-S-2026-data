#include <bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510;
const long long INF=1e17;
vector<pair<int,int> > stat[M];
int c,n,m,d,q,w[M],g[N][N];
long long dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k,aj,tj;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>aj>>tj;
            stat[aj].push_back({i,tj});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto [s,sd]:stat[i]){
            for(auto [t,td]:stat[i]){
                if(s<=t)continue;
                if(!g[s][t])g[t][s]=sd+td;
                else g[t][s]=min(g[s][t],sd+td);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=dis[j][i]=(g[i][j]?g[i][j]:INF);
            // cout<<g[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            long long r=dis[i][j];
            for(int k=1;k<=n;k++){
                r=min(r,dis[i][k]+dis[k][j]);
            }
            dis[i][j]=r;
            // cout<<dis[i][j]<<" ";
        }
        // cout<<endl;
    }
    while(q--){
        int x,y;
        long long ans=INF;
        cin>>x>>y;
        for(auto [s,sd]:stat[x]){
            for(auto [t,td]:stat[y]){
                ans=min(ans,sd+td+dis[s][t]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/