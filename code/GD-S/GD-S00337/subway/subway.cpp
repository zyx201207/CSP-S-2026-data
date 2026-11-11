#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5;
const int N=505;
const int D=22;
int c,n,m,d,q,w[M],l[M],V[M][D],W[M][D];
ll dis[N][N];
void Floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) 
            dis[i][j]=(ll)4e18;
        dis[i][i]=0;
    }
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            for(int j=1;j<=l[a];j++)
                dis[V[a][j]][i]=dis[i][V[a][j]]=min(dis[V[a][j]][i],(ll)W[a][j]+(ll)t);
            V[a][++l[a]]=i;
            W[a][l[a]]=t;
        }
    }
    Floyd();
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=(ll)4e18;
        for(int j=1;j<=l[x];j++)
            for(int k=1;k<=l[y];k++)
                ans=min(ans,(ll)W[x][j]+(ll)W[y][k]+dis[V[x][j]][V[y][k]]);
        cout<<ans+(ll)w[x]+(ll)w[y]<<'\n';
    }
    return 0;
}