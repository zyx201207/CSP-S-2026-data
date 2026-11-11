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
int n,d;
const int N=2e6+10;
int x[N],R[N],f[N],ct[N],g[N];
vector<array<int,2>>cl[N];
int res;
void get(int l,int r) {
    rep(i,0,r-l+1) ct[i]=false;
    int le=0;
    rep(j,l,r) f[j]=1e18,g[j]=0;
    rep(j,l,r) {
        f[j]=false;
        g[j]=1;
        ct[f[j]]++;
        if(R[j]+1<=r) cl[R[j]+1].pb({f[j],g[j]});
        rep(k,j+1,r) {
            for(auto to:cl[k]) ct[to[0]]-=to[1];
            cl[k].clear();
            while(!ct[le]&&le<=r-l+1) le++;
            f[k]=le+1;
            g[k]=ct[le];
            ct[f[k]]+=g[k];
            if(R[k]+1<=r) cl[R[k]+1].pb({f[k],g[k]});
            if(g[k]==2) res++;
        }
        rep(j,0,r-l+1) ct[j]=false;
        le=0;
    }
}
void get1(int l,int r) {
    rep(j,l,r) {
        int p=R[j];
        int f=0;
        while(p<r) {
            if(R[p-1]==R[p]) {
                if(f) break;
                if(R[p-2]==R[p]) break;
                f|=1;
                res+=(R[p]-max(p,R[p-2]));
            }else {
                if(f) {
                    res+=(R[p]-R[p-1]);
                }else {
                    res+=R[p-1]-max(p,R[p-2]);
                }
            }
            if(p==R[p]) break;
            p=R[p];
        }
    }
}
void solve1() {
    res=0;
    int lst=0;
    rep(i,1,n) {
        if(x[i+1]-x[i]>d) {
            get1(lst+1,i);
            lst=i;
        }
    }
    if(lst+1<=n) {
        get1(lst+1,n);
    }
    printf("%lld\n",res);
}
void solve() {
    in(n),in(d);
    rep(i,1,n) in(x[i]);
    rep(i,1,n) R[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
    if(n>5000) {
        solve1();
        return;
    }
    int lst=0;
    res=0;
    rep(i,1,n-1) {
        if(x[i+1]-x[i]>d) {
            get(lst+1,i);
            lst=i;
        }
    }
    if(lst+1<=n) get(lst+1,n);
    printf("%lld\n",res);
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    in(c),in(T);
    while(T--) {
        solve();
    }
    return false;
}
/*
g++ migrate.cpp -o m -std=c++14 -O2 "-Wl,--stack=10000000000" -Wall
*/