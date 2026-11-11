#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,dis[50020],cnt[50020],vis[50020],tim,a[50020],vd[50020],ans=0;
vector<int>G[50020];
void bfs(int st){
    vis[st]=tim;
    dis[st]=0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int now=q.front();q.pop();
        for (int r : G[now]){
            if (vis[r]==tim) {
                if (dis[now]+1==dis[r]) {
                    cnt[r]++;
                    if (cnt[r]==2) ans++;
                    else if (cnt[r]==3)ans--;
                    else continue;
                    q.push(r);
                }
                continue;
            }
            vis[r]=tim;
            dis[r]=dis[now]+1;
            cnt[r]=1;
            q.push(r);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            for (int j=i-1;j>=1;j--) {
                if (a[i]-a[j]<=m){
                    G[j].push_back(i);
                    // cout<<j<<"->"<<i<<"\n";
                } 
                else break;
            }
        }
        for (int i=1;i<=n;i++){
            tim++;
            bfs(i);
        }
        for (int i=1;i<=n;i++) G[i].clear();
        cout<<ans<<"\n";
    }
    return 0;
}