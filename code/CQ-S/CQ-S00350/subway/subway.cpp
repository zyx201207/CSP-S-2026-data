#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define rep1(i,x,y) for(int i=x;i>=y;i--)
#define pb push_back
void in(int &x) {
    x=false;
    char c=getchar();
    int f=1;
    while(c>'9'||c<'0') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    x*=f;
}
int T=1;
const int N=5e2+10,M=5e5+10,inf=1e18;
vector<array<int,2>>v[M];
int f[N][N],w[M];
int c,n,m,d;
int q;
void solve() {
    in(c),in(n),in(m),in(d),in(q);
    rep(i,1,m) in(w[i]);
    rep(i,1,n) {
        int k;
        in(k);
        rep(j,1,k) {
            int x,t;
            in(x),in(t);
            v[x].pb({i,t});
        }
    }
    memset(f,0x3f,sizeof f);
    rep(i,1,n) f[i][i]=0;
    rep(i,1,m) {
        int len=v[i].size();
        rep(j,0,len-1) {
            rep(k,0,len-1) {
                if(j!=k) {
                    f[v[i][j][0]][v[i][k][0]]=min(f[v[i][j][0]][v[i][k][0]],v[i][j][1]+v[i][k][1]);
                }
            }
        }
    }
    rep(k,1,n) {
        rep(i,1,n) {
            rep(j,1,n) {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--) {
        int x,y;
        in(x),in(y);
        int res=inf;
        for(auto a:v[x]) {
            for(auto b:v[y]) {
                res=min(res,f[a[0]][b[0]]+a[1]+b[1]);
            }
        }
        res+=w[x]+w[y];
        printf("%lld\n",res);
    }
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    while(T--) {
        solve();
    }
    return false;
}
/*
g++ subway.cpp -o s -std=c++14 -O2 "-Wl,--stack=10000000000" -Wall
*/