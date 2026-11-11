#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,D=25;
typedef long long ll;
//n<=500,m<K<=5e5,d<=20,q<=1e5 always possible
//md^2预处理最短路，qd^2查询
int n,m,d,q,s[M][D];ll w[M],v[M][D],tot[M];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int C;
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int nd,t;
            cin>>nd>>t;
            s[nd][++tot[nd]]=i;
            v[nd][tot[nd]]=t;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=0x3f3f3f3f3f3f3f3f;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=tot[i];j++){
            for(int k=j+1;k<=tot[i];k++){
                int x=s[i][j],y=s[i][k];
                dis[x][y]=dis[y][x]=min(dis[x][y],(ll)v[i][j]+v[i][k]);
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
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=tot[x];i++){
            for(int j=1;j<=tot[y];j++){
                ans=min(ans,w[x]+w[y]+v[x][i]+v[y][j]+dis[s[x][i]][s[y][j]]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}