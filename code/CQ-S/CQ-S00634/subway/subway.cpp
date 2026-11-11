#include <bits/stdc++.h>
#define ll long long
using namespace std;
int _,n,m,__,q,W[500005];
pair<int,int> mp[500005][20];
int mpct[500005];
ll dis[505][505];
int rd(){
    #ifdef LOCAL_WINDOWS
    #define getchar _getchar_nolock
    #else
    #define getchar getchar_unlocked
    #endif
    char ch=getchar();
    int x=0;
    while(ch<48||ch>57) ch=getchar();
    while(ch>47&&ch<58) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
    #undef getchar
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    _=rd(),n=rd(),m=rd(),__=rd(),q=rd();
    for(int i=1;i<=m;i++) W[i]=rd();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=i==j?0:0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++){
        int x=rd();
        for(int j=1;j<=x;j++){
            int u,v;
            u=rd(),v=rd();
            mp[u][mpct[u]++]={i,v};
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<mpct[i];j++){
            int u=mp[i][j].first;
            for(int k=j+1;k<mpct[i];k++){
                int v=mp[i][k].first;
                dis[u][v]=dis[v][u]=min(dis[u][v],(ll)mp[i][j].second+mp[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        x=rd(),y=rd();
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<mpct[x];i++){
            int u=mp[x][i].first;
            for(int j=0;j<mpct[y];j++){
                int v=mp[y][j].first;
                ans=min(ans,dis[u][v]+mp[x][i].second+mp[y][j].second);
            }
        }
        printf("%lld\n",ans+W[x]+W[y]);
    }
    return 0;
}
//AC!!!!! by ??16???=??46???