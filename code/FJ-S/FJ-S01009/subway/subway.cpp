#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
inline ll read(){
    ll sum=0,f=1; char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-f;
    for(;'0'<=c&&c<='9';c=getchar()) sum=(sum<<1)+(sum<<3)+c-'0';
    return sum*f;
}
inline ll Min(ll x,ll y){return x<y?x:y;}
/*-----------------*/
const int N=510;
const int M=5e5+10;
const ll inf=1e18;
int n,m,d,q; ll w[M],dis[N][N];
vector<pair<int,ll> > e[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int a=read(); ll t=read();
            e[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) dis[i][j]=inf;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int l=e[i].size();
        for(int j=0;j<l;j++)
        for(int k=0;k<l;k++){
            int X=e[i][j].fi,Y=e[i][k].fi;
            ll t=e[i][j].se+e[i][k].se;
            dis[X][Y]=Min(dis[X][Y],t);
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
        dis[j][k]=Min(dis[j][k],dis[j][i]+dis[i][k]);
    while(q--){
        int x,y; x=read();y=read();
        int lx=e[x].size(),ly=e[y].size();
        ll ans=inf;
        for(int i=0;i<lx;i++)
        for(int j=0;j<ly;j++){
            int X=e[x][i].fi,Y=e[y][j].fi;
            ll t=dis[X][Y]+e[x][i].se+e[y][j].se;
            ans=Min(ans,t+w[x]+w[y]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}