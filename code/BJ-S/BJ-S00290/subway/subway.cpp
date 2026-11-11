#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],cnt[M];
long long dis[N][N];
struct node{
    int x,t;
}b[M][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int y,t;
            cin>>y>>t;
            b[y][++cnt[y]]={i,t};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++){
            for(int k=1;k<=cnt[i];k++){
                long long dic=b[i][j].t+b[i][k].t;
                dis[b[i][j].x][b[i][k].x]=dis[b[i][k].x][b[i][j].x]=min(dis[b[i][j].x][b[i][k].x],dic);
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
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
        }else{
            long long ans=1e18;
            for(int i=1;i<=cnt[x];i++){
                for(int j=1;j<=cnt[y];j++){
                    ans=min(ans,w[x]+w[y]+dis[b[x][i].x][b[y][j].x]+b[x][i].t+b[y][j].t);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
