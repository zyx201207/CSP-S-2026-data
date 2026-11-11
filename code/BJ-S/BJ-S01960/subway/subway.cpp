#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
inline void read(int &x){
    x=0;bool neg=0;char c=getchar();
    for(;!isdigit(c);c=getchar())neg=(c=='-');
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(neg)x=-x;
}
inline void chmx(int &x,int y){
    x<y?x=y:0ll;
}
inline void chmn(int &x,int y){
    x>y?x=y:0ll;
}
int c,n,m,d,q,w[500005],k[505];
vector<pair<int,int>>line[500005];
int dis[505][505];
void slv(){
    read(c),read(n),read(m),read(d),read(q);
    for(int i=1;i<=m;i++)read(w[i]);
    for(int i=1;i<=n;i++){
        int k,a,t;
        read(k);
        for(int j=1;j<=k;j++)read(a),read(t),line[a].pb({i,t});
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++){
        for(auto [x,tx]:line[i]){
            for(auto [y,ty]:line[i]){
                chmn(dis[x][y],tx+ty);
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                chmn(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;read(x),read(y);
        int ans=1e18;
        for(auto[i,ti]:line[x])for(auto[j,tj]:line[y]){
            chmn(ans,w[x]+w[y]+ti+tj+dis[i][j]);
        }
        printf("%lld\n",ans);
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    slv();
}