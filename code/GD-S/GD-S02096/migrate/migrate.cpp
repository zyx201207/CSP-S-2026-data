#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
const int maxn=2e6;
int x[maxn],vis[maxn],dis[maxn];
vector<int> e[maxn];
void init(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=1e9;
	}
}
void bfs(int u){
	queue<int> q;
	q.push(u);
	init();
	vis[u]=1;
	dis[u]=0;
	while(q.size()){
		int now=q.front();
		q.pop();
		for(int next:e[now]){
			dis[next]=min(dis[next],dis[now]+1);
			if(!vis[next]){
				vis[next]=1;
				q.push(next);
			}
		}
	}
}
int cnt[maxn];
void dfs(int u,int step){
	if(step==dis[u]){
		cnt[u]++;
	}
	for(int next:e[u]){
		if(vis[next]) continue;
		vis[next]=1;
		step++;
		dfs(next,step);
		vis[next]=0;
		step--;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=n;i++){
			cnt[i]=0;
			vis[i]=0;
			dis[i]=1e18;
			e[i].clear();
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;x[j]-x[i]<=d&&j<=n;j++){
				e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++) vis[j]=cnt[j]=0;
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
