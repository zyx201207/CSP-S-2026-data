#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v[1000001];
int mx=-1,mxx;
int dep[1000001],fa[1000001][22];
int flag=0;
void dfs(int x,int f,int dp){
    if(dp>mx){
        mx=dp;
        mxx=x;
    }
    if(flag==1){
    fa[x][0]=f;
    for(int i=1;i<=21;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }}
    dep[x]=dp;
    for(auto i:v[x]){
        if(i==f)continue;
        dfs(i,x,dp+1);
    }
}
pair<int,int> lca(int u,int v){
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    for(int i=21;i>=0;i--){
        if(dep[fa[u][i]]>dep[v]){
            u=fa[u][i];
        }
    }
    int vv=v;
    v=fa[v][0];
    u=fa[u][0];
    if(u==v)return {u,vv};
    for(int i=21;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return {fa[v][0],v};
}
int vis[1000001],p[1000001];
bool cmp(int x,int y){
    int up=lca(x,mxx).first,upp=lca(y,mxx).first;
    return dep[x]-dep[up]>dep[y]-dep[upp];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,1,0);
        mx=-1;
        flag=1;
        int root=mxx;
        dfs(mxx,mxx,0);
        if(k>=n){
            cout<<"0\n";
            continue;
        }
        int l=1,r=n+1;
            for(int i=1;i<=n;i++){
                p[i]=i;
            }
            sort(p+1,p+1+n,cmp);
            int ans=0x3f3f3f3f;
            cout<<1;
        while(l<r){
            int mid=l+r>>1;
            int sum=dep[mxx]-mid*2;
            if(sum>k+1){
                l=mid+1;
                continue;
            }
            int now=mxx;
            while(now!=root){
                if(-dep[now]+dep[mxx]>=mid&&dep[now]>=mid){
                    vis[now]=1;
                }else{
                    vis[now]=0;
                }
            }
            int maxx=0;
            for(int i=1;i<=n;i++){
                if(vis[i])continue;
                int lc=lca(i,mxx).first;
                int lcc=lca(i,mxx).second;
                if(vis[lcc]!=1)continue;
                if(dep[i]-dep[lc]<=mid)continue;
                sum+=dep[i]-dep[lc]-mid;
                vis[lcc]=2;
                maxx=max(dep[i]-dep[lc]-mid,maxx);
            }
            if(sum-mid>k){
                l=mid+1;
            }else{
                r=mid;
                ans=min(ans,r);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
