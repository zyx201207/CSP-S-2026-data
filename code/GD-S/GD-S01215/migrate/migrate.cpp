#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int maxn = 2e6+5;
int c,t;
int n,d;
int a[maxn];
struct edge{
	int to,time;
};
int dis[maxn];
int cnt[maxn];
vector<edge> g[maxn];
void dij(int start){
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	dis[start] = 0;
	cnt[start] = 1;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,start});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		for(edge qq : g[u]){
			int to = qq.to;
			int w = qq.time;
			if(dis[to] > dis[u]+w){
				dis[to] = dis[u]+w;
				cnt[to] = cnt[u];
				q.push({dis[to],to});
			}else if(dis[to] == dis[u]+w){
				cnt[to] = (cnt[to]+cnt[u]);
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i == j) continue;
				int num = abs(a[i]-a[j]);
				if(num > d) continue;
				g[i].push_back({j,num});
				g[j].push_back({i,num});
			}
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int k=1;k<=n;k++){
				if(k == i) continue;
				if(cnt[k] == 2) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
