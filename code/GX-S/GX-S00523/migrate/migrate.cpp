#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,t,n,d,aans,x[200010],to[200010],ans;
map <int,int> c,vis;
vector <int> useddd;
void dfs(int u,int v,int ct){
    if(u>v) return;
    if(u==v){
        c[ct]++;
        ans=min(ans,ct);
        if(!vis[ct]){
            vis[ct]=1;
            useddd.push_back(ct);
        }
        return;
    }
    if(u==to[u]) return;
    for(int i=u+1;i<=to[u];i++) dfs(i,v,ct+1);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cc>>t;
    while(t--){
        aans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            to[i]=(upper_bound(x+1,x+n+1,x[i]+d)-x-1);
        }
        for(int u=1;u<n;u++){
            for(int v=u+1;v<=n;v++){
                ans=1e18;
                dfs(u,v,0);
                if(c[ans]==2) aans++;
                for(int i:useddd){
                    c[i]=0;
                    vis[i]=0;
                }
                useddd.clear();
            }
        }
        cout<<aans<<'\n';
    }
    return 0;
}
