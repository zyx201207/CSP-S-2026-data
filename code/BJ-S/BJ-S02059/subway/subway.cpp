#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
int c,n,m,d,q;
ll dis[M][M],ans;
map<int,int>ds[N];
int w[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,p,v;j<=k;j++){
            cin>>p>>v;
            ds[p][i]=v;
        }
    }
    //
    memset(dis,63,sizeof dis);
    for(int i=1;i<=m;i++){
        for(pair<int,int>u:ds[i]){
            for(pair<int,int>v:ds[i]){
                dis[u.first][v.first]=min(dis[u.first][v.first],1ll*u.second+v.second);
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    //
    for(int u_,v_;q--;){
        cin>>u_>>v_;
        ans=1e18;
        for(pair<int,int>u:ds[u_]){
            for(pair<int,int>v:ds[v_]){
                ans=min(ans,dis[u.first][v.first]+u.second+v.second);
            }
        }
        ans+=w[u_]+w[v_];
        cout<<ans<<'\n';
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
