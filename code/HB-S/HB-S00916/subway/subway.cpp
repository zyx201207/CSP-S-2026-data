#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=1e9+7;
const int maxn=500;
ll c,n,m,d,q,w[maxn],dis[maxn][maxn],l[maxn][20],o[maxn][20];
void floyd(){
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=500;i++)for(int j=1;j<=500;j++)dis[i][j]=INF;
    for(int i=1;i<=500;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int x=1;x<=n;x++){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>l[x][i]>>o[x][i];
        }
        for(int i=1;i<=k;i++){
            for(int j=i+1;j<=k;j++){
                ll u=l[x][i],v=l[x][j],w=o[x][i]+o[x][j];
                dis[u][v]=min(dis[u][v],w);
                dis[v][u]=min(dis[v][u],w);
            }
        }
    }
    floyd();
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<"\n";
    }
    return 0;
}
