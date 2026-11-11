#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f;
int dp[N][2],n,c,t;
long long a[N],ans,cnt[N],d,dist[N];
vector<int>v[N];
bool vis[N];
void bfs(int u){
    for(int i=1;i<=u;i++)dist[i]=inf,cnt[i]=0,vis[i]=0;
    cnt[u]=1;
    dist[u]=0;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(vis[t])continue;
        vis[t]=true;
        for(auto i:v[t]){
            if(!vis[i]&&dist[i]>=dist[t]+1){
                if(dist[i]==dist[t]+1){
                    cnt[i]+=cnt[t];
                }
                else{
                    cnt[i]=cnt[t];
                    dist[i]=dist[t]+1;
                    q.push(i);
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            v[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i-1;j;j--){
                if(a[i]-a[j]<=d)v[i].push_back(j);
                else break;
                //cout<<j<<"*";
            }

            bfs(i);
            for(int j=1;j<i;j++){
                //cout<<cnt[j]<<"\n";
                if(cnt[j]==2)ans++;
            }
            //cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
