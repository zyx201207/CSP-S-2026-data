#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,D;
vector<int> E[N];
int d[N],fa[N],f[N],g[N],mx[N],sum[N],rt,ans,ssum;
void pdfs1(int u,int pa){
    d[u]=d[pa]+1;
    for(auto v:E[u]){
        if(v==pa) continue;
        pdfs1(v,u);
    }
}
void pdfs2(int u,int pa){
    d[u]=d[pa]+1;fa[u]=pa;
    for(auto v:E[u]){
        if(v==pa) continue;
        pdfs2(v,u);
    }
}
void init(){
    int x=0,y=0;
    pdfs1(1,0);
    x=max_element(d+1,d+n+1)-d;
    pdfs2(x,0);
    y=max_element(d+1,d+n+1)-d;
    int len=d[y]-1;
    rt=y;for(int i=1;i<+len/2;i++) rt=fa[rt];
    pdfs2(rt,0);
}
//vector<int> vec;
void pdfs(int u,int pa,int dep){
    //d[u]=d[pa]+1;fa[u]=pa;
    mx[u]=dep;sum[u]=0;
    for(auto v:E[u]){
        if(v==pa) continue;
        pdfs(v,u,dep+1);
        mx[u]=max(mx[u],mx[v]);
        sum[u]+=sum[v];
    }if(mx[u]-dep>=D) sum[u]++;
    //if(mx-dep==D) vec.push_back(u);
}

void dfs(int u,int pa,int dep){
    f[u]=0;d[u]=0;mx[u]=dep;
    for(auto v:E[u]){
        if(v==pa) continue;
        dfs(v,u,dep+1);
        if(f[v])
            if(d[v]-dep>D) f[v]+=d[v]-(dep+D),d[v]=dep+D;
        if(f[v]){
            if(f[u]){
                f[u]+=f[v]+(d[u]-dep)+(d[v]-dep-1);
                d[u]=dep;
            }else{
                int ds=mx[u]-dep;
                if(d[v]-dep+ds>D) f[v]+=d[v]-(dep+D-ds),d[v]=dep+D-ds;
                f[u]=f[v];d[u]=d[v];
            }
        }else{
            if(f[u]){
                int ds=mx[v]-dep;
                if(d[u]-dep+ds>D) f[u]+=d[u]-(dep+D-ds),d[u]=dep+D-ds;
            }
        }
        mx[u]=max(mx[u],mx[v]);
        if(mx[u]-dep>=D&&!f[u]) f[u]=1,d[u]=dep;
    }ans=min(ans,sum[rt]-sum[u]+max(f[u],1));
    //cout<<u<<' '<<dep<<' '<<mx[u]<<' '<<d[u]<<' '<<f[u]<<' '<<sum[u]<<' '<<sum[rt]<<'\n';
}
int tmp[4050][4050];

/*
void dfs0(int u,int pa){

}
*/
bool check(int x){
    D=x;ans=n+10;
    for(int i=1;i<=n;i++) sum[i]=0;
    pdfs(rt,0,1);
    if(max(sum[rt],1)<=k) return 1;
    for(int i=1;i<=n;i++){
        dfs(i,0,1);
        for(int j=1;j<=n;j++) tmp[i][j]=f[j];
    }
    ans=n+10;
    for(int i=1;i<=n;i++){
        if(i!=rt){
            ans=min(ans,tmp[fa[i]][i]+tmp[i][fa[i]]);
        }
    }
    //dfs(rt,0,1);
    //cout<<ans<<'\n';
    if(ans<=k) return 1;else return 0;
}
void slv(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) E[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }init();
    if(k==n){
        cout<<0<<'\n';return ;
    }
    //check(9);return ;
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;else l=mid+1;
    }cout<<l<<'\n';
}
int tid;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>tid>>t;
    while(t--) slv();
    return 0;
}