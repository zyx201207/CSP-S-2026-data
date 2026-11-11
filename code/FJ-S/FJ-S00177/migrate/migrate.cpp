#include<bits/stdc++.h>
using namespace std;
const int N=2e6 +10;
int a[N],dis[N], vis[N],cnt[N];
vector<int> e[N];
void djs(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[x]=0;
	queue<int> q;
	q.push(x);
	while(q.size()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(dis[v]>dis[u]+1&&!vis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
				cnt[v] = 0;
			}
			if(dis[v] == dis[u] + 1){
				cnt[v] += 1;
			}
		}
	}
}
int main(){
	freopen("migrate.in", "r",stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t --){
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof a);
		for(int i =1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		for(int i = 2;i<=n;i++){
			for(int j =1;j<i; j++){
				if(abs(a[i] - a[j])<=d){
//					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof cnt);
			djs(i);
			for(int j=1;j<=n; j++){
				if(i== j)continue;
				if(cnt[j]==2){
					ans ++;
//					cout<<i<<' '<<j<<'\n';
				}
//				cout<<i<<' '<<j<<' ' << cnt[j]<<'\n';
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
