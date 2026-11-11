#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000000],v[2000000],dis[2000000],f[2000000],ans=1e9;
vector<int> edge[2000000];
int find(int x){
    if(f[x]<0) return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(f[x]<f[y]){
        f[x]+=f[y];
        f[y]=x;
    }else{
        f[y]+=f[x];
        f[x]=y;
    }
}
void dfs(int x,int fa,int now){
    dis[x]=min(dis[x],now);
    for(auto it:edge[x]){
        if(it==fa) continue;
        dfs(it,x,now+1);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) edge[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans=1e9;
        if(n<=10){
            for(int s=0;s<(1<<n);s++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    if((1<<i)&s) cnt++;
                }
                if(cnt!=k) continue;
                for(int i=1;i<=n;i++) dis[i]=1e9;
                for(int i=0;i<n;i++){
                    if((1<<i)&s){
                        dfs(i+1,0,0);
                    }
                }
                for(int i=1;i<=n;i++) f[i]=-1;
                for(int i=1;i<=n;i++){
                    for(auto it:edge[i]){
                        if((s&(1<<(i-1))) && (s&(1<<(it-1)))){
                            merge(i,it);
                        }
                    }
                }
                int tot=0;
                for(int i=1;i<=n;i++){
                    if(f[i]<0) tot++;
                }
                if(tot>n-k+2){
                    continue;
                }
                int res=0;
                for(int i=1;i<=n;i++){
                    res=max(res,dis[i]);
                }
                ans=min(ans,res);
            }
            cout<<ans<<endl;
            continue;
        }
        if(k>=n/2){
            cout<<(k<n)<<endl;
        }else{
            cout<<(n/2-k+3)/4+1<<endl;
        }
    }
    
    return 0;
}

