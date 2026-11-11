#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll c,t,n,k,u,v,d[25],f[25];
ll find(ll x){return (f[x]==x)?x:f[x]=find(f[x]);}
vector<ll> G[25];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            cin>>u>>v;
            G[u].push_back(v);G[v].push_back(u);
        }
        int res=1e9;
        for(int S=0;S<(1<<n);S++){
            if(__builtin_popcount(S)!=k) continue;
            queue<int> q;
            for(int i=1;i<=n;i++) d[i]=1e9,f[i]=i;
            for(int i=1;i<=n;i++){
                if(S&(1<<i-1)){
                    q.push(i),d[i]=0;
                    for(int j:G[i]){
                        if(S&(1<<j-1)) f[find(i)]=find(j);
                    }
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(S&(1<<i-1))cnt+=(f[i]==i);
            }
            if(cnt>2) continue;
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int v:G[u]){
                    if(d[v]>d[u]+1){
                        d[v]=d[u]+1;q.push(v);
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++) ans=max(ans,d[i]);
            res=min(res,ans);
        }
        cout<<res<<"\n";
    }
    return 0;
}
