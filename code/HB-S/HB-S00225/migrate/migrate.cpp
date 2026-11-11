#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c,t;
int n,d,x[N],dis[N],cnt[N],ans;
bool vis[N];
vector<int> ed[N];
queue<int> q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            int len=ed[i].size();
            for(int j=0;j<len;j++){
                ed[i].pop_back();
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    ed[i].push_back(j);
                }
            }
        }
        for(int s=1;s<=n;s++){
            memset(dis,0x3f,sizeof dis);
            memset(cnt,0,sizeof cnt);
            memset(vis,0,sizeof vis);
            q.push(s);
            dis[s]=0,vis[s]=1,cnt[s]=1;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:ed[u]){
                    if(vis[v]){
                        if(dis[v]==dis[u]+1){
                            cnt[v]+=cnt[u];
                        }
                        continue;
                    }
                    vis[v]=1;
                    q.push(v);
                    dis[v]=dis[u]+1;
                    cnt[v]+=cnt[u];
                }
            }
            for(int j=s+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
