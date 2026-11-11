#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rd(){int x=0,fh=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') fh=-1;ch=getchar();}while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*fh;}
const int N=510,M=5e5+10;
const ll inf=2e18;
int n,m,d,q,cnt[M],val[M];
ll f[N][N];
struct node{int u,w;}a[M][20];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++) val[i]=rd(),cnt[i]=-1;
    for(int i=1,k;i<=n;i++){
        k=rd();
        for(int j=1,x,y;j<=k;j++){
            x=rd(),y=rd();
            cnt[x]++;
            a[x][cnt[x]]={i,y};
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int x=0;x<=cnt[i];x++) for(int y=x+1;y<=cnt[i];y++){
            f[a[i][x].u][a[i][y].u]=f[a[i][y].u][a[i][x].u]=a[i][x].w+a[i][y].w;
        }
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    int u,v;
    ll ans;
    while(q--){
        u=rd(),v=rd();
        ans=inf;
        for(int x=0;x<=cnt[u];x++) for(int y=0;y<=cnt[v];y++) ans=min(ans,a[u][x].w+f[a[u][x].u][a[v][y].u]+a[v][y].w);
        printf("%lld\n",ans+val[u]+val[v]);
    }
    return 0;
}