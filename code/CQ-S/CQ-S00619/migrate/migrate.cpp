#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rd(){ll x=0,fh=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') fh=-1;ch=getchar();}while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*fh;}
const int N=2e6+10,infint=1e9;
const ll inf=3e18;
int n,r[N],dfn[N],si[N],cnt;
ll d,a[N],ans;
vector<pair<int,int> > upd[N];
vector<int> g[N];

void dfs(int u,int fa){
    si[u]=1,dfn[u]=++cnt;
    for(int v:g[u]){
        if(v==fa) continue;
        dfs(v,u);si[u]+=si[v];
    }
}

struct node{
    int mn1,c1,mn2,c2;

    friend node operator+(const node &x,const node &y){
        int mn1=min(x.mn1,y.mn1);
        int mn2=min(x.mn1==mn1?x.mn2:x.mn1,y.mn1==mn1?y.mn2:y.mn1);
        return {mn1,(x.mn1==mn1?x.c1:(x.mn2==mn1?x.c2:0))+(y.mn1==mn1?y.c1:(y.mn2==mn1?y.c2:0)),
                mn2,(x.mn1==mn2?x.c1:(x.mn2==mn2?x.c2:0))+(y.mn1==mn2?y.c1:(y.mn2==mn2?y.c2:0))};
    }
}s[N<<2];
int tag[N<<2];

void built(int k,int l,int r){
    tag[k]=0;
    s[k]={0,r-l+1,infint,0};
    if(l==r) return;
    int mid=l+r>>1;
    built(k<<1,l,mid),built(k<<1|1,mid+1,r);
}

void calc(int k,int v){
    tag[k]+=v;
    s[k].mn1+=v,s[k].mn2+=v;
}

void pushdown(int k){
    if(!tag[k]) return;
    calc(k<<1,tag[k]),calc(k<<1|1,tag[k]);
    tag[k]=0;
}

void change(int k,int l,int r,int x,int y,int v){
    if(x>y) return;
    if(x<=l&&r<=y) return calc(k,v);
    pushdown(k);
    int mid=l+r>>1;
    if(x<=mid) change(k<<1,l,mid,x,y,v);
    if(y>mid) change(k<<1|1,mid+1,r,x,y,v);
    s[k]=s[k<<1]+s[k<<1|1];
}

node ask(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y) return s[k];
    pushdown(k);
    int mid=l+r>>1;
    if(y<=mid) return ask(k<<1,l,mid,x,y);
    if(x>mid) return ask(k<<1|1,mid+1,r,x,y);
    return ask(k<<1,l,mid,x,y)+ask(k<<1|1,mid+1,r,x,y);
}

void solve(){
    n=rd(),d=rd();
    for(int i=1;i<=n;i++) a[i]=rd(),g[i].clear();
    int p=n;
    for(int i=n;i;i--){
        while(p>=i&&a[p]-a[i]>d) p--;
        r[i]=p;
        if(i<p) g[p].push_back(i);
    }
    for(int i=1;i<=n;i++) upd[i].clear(),dfn[i]=0;
    cnt=0;
    for(int i=n;i;i--) if(!dfn[i]) dfs(i,0);
    for(int i=1;i<=n;i++){
        if(r[i]==i){
            upd[i+1].push_back({i,2});
            continue;
        }
        if(i-1>0){
            if(r[i-1]==r[i]) upd[i+1].push_back({i,1});
            else if(r[i-1]>i){
                upd[i+1].push_back({i,1});
                upd[r[i-1]+1].push_back({i,-1});
                if(r[i-1]+1==r[i]){
                    if(r[r[i]-1]==r[r[i]]){
                        upd[r[i]+1].push_back({i,1});
                    }
                    else{
                        upd[r[i]+1].push_back({i,1});
                        upd[r[r[i]-1]+1].push_back({i,-1});
                    }
                }
            }
        }
        if(i-2>0){
            if(r[i-2]==r[i]) upd[i+1].push_back({i,1});
            else if(r[i-2]>i){
                upd[i+1].push_back({i,1});
                upd[r[i-2]+1].push_back({i,-1});
            }
        }
    }
    ans=0;
    built(1,1,n);
    for(int i=1;i<=n;i++){
        for(auto x:upd[i]){
            change(1,1,n,dfn[x.first]+1,dfn[x.first]+si[x.first]-1,x.second);
        }
        ans+=(s[1].mn1==1?s[1].c1:0)+(s[1].mn2==1?s[1].c2:0);
    }
    printf("%lld\n",ans);
}

int main(){
    a[0]=-inf;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    rd();int t=rd();
    while(t--) solve();
    return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/