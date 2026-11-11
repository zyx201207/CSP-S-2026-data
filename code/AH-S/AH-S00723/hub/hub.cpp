#include<bits/stdc++.h>
using namespace std;
long long h[500005],vtx[500005],nxt[500005],idx;
void add(long long a,long long b){
    vtx[idx]=b;
    nxt[idx]=h[a];
    h[a]=idx;
    idx++;
}
long long c,t,n,k,a[1000005],d[1000055],s,ans;
bool vis[1000005];
struct z{
    int u,v;
}e[1000005];
void dfs(int s,int th){
    d[th]++;
    int p=h[s];
    while(p!=-1){
        if(vis[vtx[p]]==0){
            vis[vtx[p]]=1;
            dfs(vtx[p],th+1);
        }
        p=nxt[p];
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        memset(h,-1,sizeof(h));
        memset(a,0,sizeof(a));
        for(int i=1;i<n;i++){
            cin>>e[i].u>>e[i].v;
            add(e[i].u,e[i].v);
            add(e[i].v,e[i].u);
        }
        ans=1e9;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            memset(d,0,sizeof(d));
            vis[i]=1;
            dfs(i,1);
            s=0;
            for(int j=1;j<=n;j++){
                if(s<k&&s+d[j]>k){
                    ans=min(ans,(long long)j-1);
                }
                s+=d[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
