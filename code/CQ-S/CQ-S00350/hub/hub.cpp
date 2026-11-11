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
const int N=1e6+10;
vector<int>v[N];
int n,k;
int fl=0;
int f[N],mx[N],fat[N];
int mx1[N];
void dfs(int x,int fa) {
    fat[x]=fa;
    multiset<int>se;
    mx[x]=false;
    for(auto to:v[x]) {
        if(to==fa) continue;
        dfs(to,x);
        mx[x]=max(mx[x],mx[to]+1);
        se.insert(mx[to]+1);
    }
    for(auto to:v[x]) {
        if(to==fa) continue;
        se.erase(se.find({mx[to]+1}));
        if(se.size()) mx1[to]=(*se.rbegin());
        se.insert({mx[to]+1});
    }
}
void dfs1(int x,int fa,int d) {
    f[x]=false;
    for(auto to:v[x]) {
        if(to==fa) continue;
        dfs1(to,x,d);
        if(mx[to]<d) {
            f[x]+=0;
        }else f[x]+=f[to];
    }
    f[x]++;
}
int vis[N],g[N],mxd[N];
int mn=1e18;
void dfs3(int x,int fa) {
    mxd[x]=false;
    for(auto to:v[x]) {
        if(to==fa||vis[to]) continue;
        dfs3(to,x);
        mxd[x]=max(mxd[x],mxd[to]+1);
    }
}
int dfs2(int x,int fa,int len,int d) {
    int tt=0;
    vector<int>vk,vk1;
    for(auto to:v[x]) {
        if(to==fa||vis[to]) continue;
        vk.pb(mxd[to]);
        vk1.pb(mxd[to]);
    }
    int ln=vk.size();
    rep(i,1,ln-1) vk[i]=max(vk[i-1],vk[i]);
    rep1(i,ln-2,0) vk1[i]=max(vk1[i],vk1[i+1]);
    int t=0;
    for(auto to:v[x]) {
        if(to==fa||vis[to]) continue;
        int p1=dfs2(to,x,max({len+1,(t-1>=0?vk[t-1]+1:0),(t+1<=ln-1?vk1[t+1]+1:0)}),d);
        if(mxd[to]>=d) tt+=p1;
        t++;
    }
    vk.clear();
    vk1.clear();
    vk.shrink_to_fit();
    vk1.shrink_to_fit();
    if(len<=d) mn=min(mn,tt+1);
    return tt+1;
}
int check(int x) {
    fl=0;
    dfs1(1,0,x);
    if(f[1]<=k) return 1;
    rep(i,2,n) {
        if(f[i]>k) continue;
        int p=i,d=0;
        vector<int>cl;
        while(d<=k&&p) {
            d++;
            int tt=d+mx1[p];
            vis[p]=1;
            cl.pb(p);
            p=fat[p];
            if(tt>x) {
                break;
            }
        }
        if(!p) {
            for(auto to:cl) vis[to]=false;
            return 1;
        }
        mn=1e18;
        dfs3(p,0);
        dfs2(p,0,0,x);
        int now=f[i]+mn;
        for(auto to:cl) vis[to]=false;
        if(now<=k) {
            return 1;
        }
    }
    return 0;
}
void solve() {
    in(n),in(k);
    rep(i,1,n) v[i].clear();
    rep(i,1,n-1) {
        int x,y;
        in(x),in(y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    int l=0,r=n-1,res=0;
    while(l<=r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    printf("%lld\n",res);
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c;
    in(c),in(T);
    while(T--) {
        solve();
    }
    return false;
}
/*
g++ hub.cpp -o h -std=c++14 -O2 "-Wl,--stack=10000000000" -Wall
*/