#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll n,d;
ll a[N];
vector<int> e[N];
bool vis[N];
ll dis[N],cnt[N];
void bfs(int s){
	queue<int> q;
	for(int i=1;i<=n;i++){
		vis[i]=0,dis[i]=1e9,cnt[i]=0;
	}
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	vis[1]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d)e[i].push_back(j);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
