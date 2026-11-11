#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
const int N=1e6+10;
vector<int> mp[N];
int dep[N],fat[N][21];
int lim;
void dfs(int p,int f){
    fat[p][0]=f;
    fr(i,1,20)fat[p][i]=fat[fat[p][i-1]][i-1];
    for(auto x:mp[p]){
        if(x==f)continue;
        dep[x]=dep[p]+1;
        dfs(x,p);
    }
}
struct info{
    bool zt;
    // zt==0
    int mxlen; // point cnt
    // zt==1
    int lasp,sum;
};
int Lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);//dep[u]<=dep[v]
    dfr(i,20,0)if(dep[fat[v][i]]>=dep[u])v=fat[v][i];
    if(u==v)return u;
    dfr(i,20,0)if(fat[v][i]!=fat[u][i])v=fat[v][i],u=fat[u][i];
    return fat[u][0];
}
int dis(int u,int v){
    return dep[v]+dep[u]-2*dep[Lca(u,v)]+1;
}
inline int jp(int p,int s){
    dfr(i,20,0)if(s&(1<<i))p=fat[p][i];
    return p;
}
int jmp(int p,int mb,int stp){
    int lca=Lca(p,mb);
    int dx=min(stp,dep[p]-dep[lca]);
    p=jp(p,dx),stp-=dx;
    if(stp==0)return p;
    //assert(dep[mb]-dep[lca]-stp>0);
    return jp(mb,dep[mb]-dep[lca]-stp);
}
void upd(info &a,const info &b,int pos){
    if(a.zt&&b.zt){
        if(a.lasp!=pos&&b.lasp!=pos)a.sum+=dis(a.lasp,pos)-1+dis(a.lasp,b.lasp)-2;
        else if(a.lasp!=pos)a.sum+=dis(a.lasp,pos)-2;
        else if(b.lasp!=pos)a.sum+=dis(a.lasp,b.lasp)-2;
        else a.sum--;
        a.lasp=pos,a.sum+=b.sum;
        return;
    }
    if(a.zt){
        if(dis(pos,a.lasp)+b.mxlen-2>lim){
            int nw=jmp(a.lasp,pos,dis(pos,a.lasp)+b.mxlen-2-lim);
            //assert(dis(pos,a.lasp)+b.mxlen-2-lim<dis(a.lasp,pos));
            a.sum+=dis(pos,a.lasp)+b.mxlen-2-lim;
            a.lasp=nw;
        }
        return ;
    }
    if(b.zt){
        info tb=b;
        upd(tb,a,pos);
        a=tb;
        return;
    }
    a.mxlen=max(a.mxlen,b.mxlen);
}
void yc(info &a,int pos){
    if(a.zt){
        if(dis(pos,a.lasp)>lim+1){
            //assert(dis(pos,a.lasp)==lim+2);
            a.sum++;
            a.lasp=jmp(a.lasp,pos,1);
        }
    }
    else{
        a.mxlen++;
        if(a.mxlen==lim+1){
            a.zt=1,a.sum=1,a.lasp=pos;
        }
    }
}
info dp[N],ys[N],zer;
void dfs1(int p,int f){
    dp[p]=zer;
    for(auto x:mp[p]){
        if(x==f)continue;
        dfs1(x,p);
        ys[x]=dp[x],yc(ys[x],p);
        upd(dp[p],ys[x],p);

    }
}
bool flg=0;
int k;
void dfs2(int p,int f,info t){
    if(flg)return;
    vector<info> pre,suf;
    pre.resize(mp[p].size()+2);
    suf.resize(mp[p].size()+2);
    pre[0]=t;
    suf[mp[p].size()+1]=zer;
    fr(i,1,mp[p].size()){
        if(mp[p][i-1]==f)pre[i]=pre[i-1];
        else pre[i]=pre[i-1],upd(pre[i],ys[mp[p][i-1]],p);
    }
    dfr(i,mp[p].size(),1){
        if(mp[p][i-1]==f)suf[i]=suf[i+1];
        else suf[i]=suf[i+1],upd(suf[i],ys[mp[p][i-1]],p);
    }
    fr(i,1,mp[p].size()){
        if(mp[p][i-1]==f)continue;
        upd(pre[i-1],suf[i+1],p);
        if(pre[i-1].sum+dp[mp[p][i-1]].sum+(pre[i-1].zt==0)+(dp[mp[p][i-1]].zt==0)<=k){
            flg=1;
            return;
        }
    }
    fr(i,1,mp[p].size()){
        if(mp[p][i-1]==f)continue;
        yc(pre[i-1],mp[p][i-1]);
        dfs2(mp[p][i-1],p,pre[i-1]);
    }
 /*   for(auto x:mp[p]){
        if(x==f)continue;
        info tp=t;
        for(auto tx:mp[p])if(tx!=f&&tx!=x){
            upd(tp,ys[tx],p);
        }

        if(tp.sum+dp[x].sum+(tp.zt==0)+(dp[x].zt==0)<=k){
           //     cout << p << " " << x << " " << tp.sum << " " << dp[x].sum << endl;
            flg=1;
            return;
        }

        yc(tp,x);
        dfs2(x,p,tp);
    }*/
}
bool check(int mid){
    flg=0;
    lim=mid;
    dfs1(1,1);
    dfs2(1,1,zer);
    return flg||((dp[1].sum+(dp[1].zt==0))<=k);
}
void solve(){
    int n;
    cin >> n >> k;
   // cout << n << endl;
    fr(i,1,n)mp[i].clear();
    fr(i,1,n-1){
        int u,v;
        cin >> u >> v;
        mp[u].pb(v),mp[v].pb(u);
    }
    if(k==n){
        cout << 0 << endl;
        return;
    }
    dfs(1,1);
    //cout << check(1) << endl,exit(0);
    int l=0,r=n,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))res=mid,r=mid-1;
        else l=mid+1;
    }
    cout << res << endl;
    //exit(0);
}
signed main(){
    zer.zt=0,zer.mxlen=1,zer.sum=zer.lasp=0;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin >> c >> T;
    while(T--)solve();
    return 0;
}
