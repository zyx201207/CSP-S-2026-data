#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
bool vis[500005];
vector<pair<int,int> > g[500005];
int t[505][1005];
long long ans=0x3f3f3f3f3f3f;
void dfs(int now,long long time,int xian,int en){
//    cout<<time<<endl;
    if(time>ans){
        return;
    }
    if(now==en){
        ans=min(ans,time+t[xian][en]);
        return;
    }
    for(auto u:g[now]){
        int v=u.first;
        int k=u.second;
        if(vis[v]){
            continue;
        }
        if(xian==-1){
            vis[v]=1;
            dfs(v,time+t[k][now],k,en);
        }
        if(k==xian){
            vis[v]=1;
            dfs(v,time,k,en);
        }
        else{
            vis[v]=1;
            dfs(v,time+t[xian][now]+t[k][now],k,en);
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a1,t1,a2,t2,a0;
        for(int j=1;j<=k;j++){
            if(j%2){
                cin>>a1>>t1;
                t[i][a1]=t1;
                if(j>=2){
                    g[a2].emplace_back(a1,i);
                }
                else{
                    a0=a1;
                }
                if(j==k){
                    g[a1].emplace_back(a0,i);
                }
            }
            else{
                cin>>a2>>t2;
                t[i][a2]=t2;
                if(j>=2){
                    g[a1].emplace_back(a2,i);
                }
                if(j==k){
                    g[a2].emplace_back(a0,i);
                }
            }
        }

    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans=0x3f3f3f3f3f3f;
        memset(vis,0,sizeof vis);
        vis[x]=1;
        dfs(x,0,-1,y);
        ans=ans+w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}
//55 72 121 139 150 157
