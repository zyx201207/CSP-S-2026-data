#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define vi vector<int>
#define vp vector<pii>
#define pb push_back
using namespace std;
const int N=505,M=5e5+5;const ll INF=4e18;
int n,m,d,Q,w[M];vp vec[M];ll dis[N][N];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-f;
        c=getchar();
    }
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c-'0'),c=getchar();
    return x*f;
}
inline void write(ll x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}
inline void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C=read();n=read(),m=read(),d=read(),Q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int id=read(),tim=read();
            vec[id].pb(mkp(i,tim));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=INF;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int id=1;id<=m;id++){
        int _siz=vec[id].size();
        for(int i=0;i<_siz;i++){
            for(int j=0;j<_siz;j++){
                if(i==j)continue;
                pii u=vec[id][i],v=vec[id][j];
                dis[u.fi][v.fi]=min(dis[u.fi][v.fi],(ll)u.se+v.se);
            }
        }
    }
    floyd();
    while(Q--){
        int x=read(),y=read();
        ll ans=INF;
        for(pii u:vec[x])
            for(pii v:vec[y])
                ans=min(ans,(ll)u.se+v.se+dis[u.fi][v.fi]);
        ans+=(ll)w[x]+w[y];
        write(ans);putchar('\n');
    }
    return 0;
}