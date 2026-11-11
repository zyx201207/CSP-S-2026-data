#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pow power
#define ull unsigned ll
template<typename T>void read(T &x){
    x=0; int f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    } 
    while(isdigit(c)) x=10*x+c-'0',c=getchar();
    x*=f;
}
template<typename T>void write(T x){
    if(x<0) putchar('-'),write(-x);
    else if(x<10) putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=505,M=5e5+5;
const ll INF=1e18;
int c,n,m,d,q,tmp[M];
ll dis[N][N];
vector<pair<int,int> >g[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(c),read(n),read(m),read(d),read(q);
    for(int i=1;i<=m;i++) read(tmp[i]);
    for(int i=1;i<=n;i++){
        int k; read(k);
        for(int j=1;j<=k;j++){
            int x,w;
            read(x),read(w);
            g[x].push_back(make_pair(i,w));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dis[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto pr1:g[i]){
            for(auto pr2:g[i]){
                int u=pr1.first;ll wu=pr1.second;
                int v=pr2.first;ll wv=pr2.second;
                dis[u][v]=min(dis[u][v],wu+wv);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        int x,y;
        ll ans=INF;
        read(x),read(y);
        for(auto pr1:g[x]){
            for(auto pr2:g[y]){
                int u=pr1.first;ll wu=pr1.second;
                int v=pr2.first;ll wv=pr2.second;
                ans=min(ans,dis[u][v]+wu+wv);
            }
        }
        writeln(ans+tmp[x]+tmp[y]);
    }
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}