#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k,re=1000000000,s[1000005];
vector<int> e[1000000+1];
void check(){
    int ans=0;
    for(int i=1;i<=n;i++){
        queue<pair<int,int>> q;
        q.push({i,0});
        bool is[n+1];
        memset(is,0,sizeof(is));
        is[i]=1;
        while(!q.empty()){
            int now=q.front().first,b=q.front().second;
            q.pop();
            if(s[now]){
                ans=max(ans,b);
                break;
            }
            for(int to:e[now]){
                if(!is[to]){
                    is[to]=1;
                    q.push({to,b+1});
                }
            }
        }
    }
    re=min(re,ans);
}
void dfs(int now,int sta,int last,int sum){
    if(sum==k){
        check();
        return;
    }
    if(sta<2){
        s[now]=1;
        for(int to:e[now]){
            if(to==last)
                continue;
            dfs(to,sta+1,now,sum+1);
        }
    }
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0,0,0);
    cout<<re<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>t>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
