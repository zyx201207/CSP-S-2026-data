#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define all(x) x.begin(),x.end()
#define int long long
#define rep(i,b,e) for(int i=(b);i<=(e);i++)
#define repd(i,b,e) for(int i=(b);i>=(e);i--)
int in(){
    int r=0;bool f=0;char c=gc();
    while(c<'0'||c>'9')f|=(c=='-'),c=gc();
    while(c>='0'&&c<='9')r=r*10+(c-'0'),c=gc();
    return f?-r:r;
}
void out(int x){
    if(x<0)pc('-'),x=-x;
    if(x<10)pc('0'+x);
    else out(x/10),pc('0'+(x%10));
}
void getmax(int&x,int y){x=y>x?y:x;}
void getmin(int&x,int y){x=y<x?y:x;}
const int N=5e5+5;
const int M=1e9+7;
const int INF=1e18;
int c,n,m,d,q;
int w[N];int dis[505][505];
struct qwq{int a,t;};
vector<qwq>G[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=in(),n=in(),m=in(),d=in(),q=in();
    rep(i,1,m)w[i]=in();
    rep(i,1,n){
        int k=in();
        rep(j,1,k){
            int a=in(),t=in();
            G[a].push_back({i,t});
        }
    }
    rep(i,1,n)rep(j,1,n)if(i!=j)dis[i][j]=INF;
    rep(i,1,m){
        int p=G[i].size();
        rep(x,1,p)rep(y,x+1,p){
            int u=G[i][x-1].a,v=G[i][y-1].a,w=G[i][x-1].t+G[i][y-1].t;
            getmin(dis[u][v],w);getmin(dis[v][u],w);
        }
    }//O(md^2)
    //Floyd O(n^3)
    rep(k,1,n)rep(i,1,n)rep(j,1,n)//
        getmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){//O(qd^2)
        int x=in(),y=in();int ans=INF;
        int xs=G[x].size(),ys=G[y].size();
        rep(i,1,xs)rep(j,1,ys){
            auto zzx=G[x][i-1],rmt=G[y][j-1];
            //cout<<"#"<<zzx.a<<' '<<rmt.a<<' '<<dis[zzx.a][rmt.a]<<endl;
            getmin(ans,zzx.t+rmt.t+dis[zzx.a][rmt.a]);
        }
        out(ans+w[x]+w[y]),pc('\n');
    }
    return 0;
}
