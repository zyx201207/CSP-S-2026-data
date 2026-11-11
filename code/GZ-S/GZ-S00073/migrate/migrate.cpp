//毕节七星关东辰实验学校 刘杰 GZ-S00073
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MX=2e6+10;

int dis[MX],a[MX];
vector<int> ed[MX];

int cnt[MX]={};int n,d;

int bfs(int s){
    memset(cnt,0,sizeof(cnt));
    memset(dis,0x3f,sizeof(dis));
    queue<pair<int,int> > q;
    q.push({s,0});
    dis[s]=0;cnt[s]=1;
    while(!q.empty()){
        pair<int,int> k=q.front();q.pop();
        for(int i=0;i<ed[k.first].size();i++){
            int v=ed[k.first][i];
            if(dis[v]>k.second+1){
                dis[v]=k.second+1;
                cnt[v]=1;
                q.push({v,dis[v]});
            }
            else if(dis[v]==k.second+1){
                cnt[v]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==2){
            ans++;
        }
    }
    return ans;
}

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ed[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n&&abs(a[i]-a[j])<=d;j++){
            ed[i].push_back(j);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=bfs(i);
    }
    cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        solve();
    }
}
