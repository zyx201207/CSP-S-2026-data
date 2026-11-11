#include<bits/stdc++.h>
using namespace std;
#define ll long long
mt19937 rnd(20261031);
int c;
int n,k;
vector<int> V[1000005];
int dis[4005][4005],mxdis[1000005],Fa[1000005];
void dfs(int u,int fa,int d,int tmp[]){
    Fa[u]=fa;
    tmp[u]=d;
    for(int v:V[u]){
        if(v==fa) continue;
        dfs(v,u,d+1,tmp);
    }
}
int m1=0,m2=0,len=0,x=0;
int lst[1000005],vis[1000005];
void dfs2(int u,int fa,int d,int &m){
    vis[u]=1;
    lst[u]=fa;
    if(d>len){
        len=d,m=u;
    }
    for(int v:V[u]){
        if(v==fa||v==x) continue;
        dfs2(v,u,d+1,m);
    }
}
int mxdn[1000005];
void dfs3(int u,int fa){
    mxdn[u]=0;
    for(int v:V[u]){
        if(v==fa||v==x) continue;
        dfs3(v,u);
        mxdn[u]=max(mxdn[u],mxdn[v]+1);
    }
}
int calc(int u,int v,int mnd){
    if(!u) return 0;
    //取直径中点m
    m1=m2=len=0;
    int st=0,ed=0;
    x=v;
    dfs2(u,v,0,st);
    len=0;
    dfs2(st,0,0,ed);
    len=dis[st][ed];
    m1=ed;
    for(int i=1;i<=len/2;i++) m1=lst[m1];
    if(len%2==1) m2=lst[m1];
    else m2=m1;
    dfs3(m1,0);
    int cnt1=0;
    for(int i=1;i<=n;i++) if(vis[i]){
        cnt1+=(mxdn[i]>=mnd);
    }
    dfs3(m2,0);
    int cnt2=0;
    for(int i=1;i<=n;i++) if(vis[i]){
        cnt2+=(mxdn[i]>=mnd);
        vis[i]=0;
    }
    int cnt=min(cnt1,cnt2);
    return max(cnt,1);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) V[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,0,dis[i]);
    }
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i]=i+1;
    shuffle(p.begin(),p.end(),rnd);
    int ans=n;
    for(int i:p){
        int l=0,r=n;
        if(calc(i,Fa[i],ans-1)+calc(Fa[i],i,ans-1)>k) continue;
        while(l<=r){
            int mid=(l+r)/2;
            if(calc(i,Fa[i],mid)+calc(Fa[i],i,mid)<=k){
                ans=min(ans,mid);
                r=mid-1;
            }else l=mid+1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}