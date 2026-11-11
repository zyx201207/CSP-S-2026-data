#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=507,M=5e5+7;
long long dx[507][507],kz[M];
struct zhantoxian{
    int to;long long val;
}zx[M][23];
int idxz[M];
vector<zhantoxian>g[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dx,0x3f,sizeof dx);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)scanf("%lld",kz+i);
    for(int i=1;i<=n;i++){
        dx[i][i]=0;
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int v;long long w;
            scanf("%d%lld",&v,&w);
            zx[v][++idxz[v]]={i,w};
        }
    }for(int i=1;i<=m;i++){
        for(int j=1;j<=idxz[i];j++){
            for(int k=j+1;k<=idxz[i];k++){
                zhantoxian a=zx[i][j],b=zx[i][k];
                dx[b.to][a.to]=dx[a.to][b.to]=min(dx[a.to][b.to],a.val+b.val);
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(i==j||i==k)continue;
                dx[k][j]=dx[j][k]=min(dx[j][k],dx[j][i]+dx[i][k]);
            }
        }
    }while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=idxz[u];i++){
            for(int j=1;j<=idxz[v];j++){
                ans=min(ans,kz[u]+kz[v]+zx[u][i].val+zx[v][j].val+dx[zx[u][i].to][zx[v][j].to]);
            }
        }cout<<ans<<'\n';
    }return 0;
}
