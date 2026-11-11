#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[15];
int dis[15][15];
int ans=167676767;
int l=0;
int n,k;
bool choice[15],vis[15];
void dfs(int o){
    if(l>k) return;
    if(o>n){
        if(l!=k) return;
        for(int i=1;i<=12;i++) vis[i]=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(choice[i]&&!vis[i]){
                cnt++;
                queue<int>q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    for(int j=0;j<v[u].size();j++){
                        int nxt=v[u][j];
                        if(choice[nxt]&&!vis[nxt]){
                            vis[nxt]=true;
                            q.push(nxt);
                        }
                    }
                }
            }
        }
        if(cnt>2) return;
        int lo=0;
        for(int i=1;i<=n;i++){
            int oo=167676767;
            for(int j=1;j<=n;j++){
                if(choice[j]){
                    oo=min(oo,dis[i][j]);
                }
            }
            lo=max(lo,oo);
        }
        ans=min(ans,lo);
        return;
    }
    l++;
    choice[o]=1;
    dfs(o+1);
    l--;
    choice[o]=0;
    dfs(o+1);
}
void solve(){
    ans=167676767;
    for(int i=1;i<=13;i++){
        for(int j=1;j<=13;j++) dis[i][j]=167676767;
        dis[i][i]=0;
        v[i].clear();
    }
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int fr,to;
        cin>>fr>>to;
        v[fr].push_back(to);
        v[to].push_back(fr);
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int j=0;j<v[u].size();j++){
                int nxt=v[u][j];
                if(dis[i][u]+1<dis[i][nxt]){
                    q.push(nxt);
                    dis[i][nxt]=dis[i][u]+1;
                }
            }
        }
    }
    dfs(1);
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
}