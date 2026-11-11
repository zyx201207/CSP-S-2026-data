#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+10;
int c,t,d,n,a[N],cnt,pre[N],dis[N],dp[N];
struct Edge{
	int from,to,next;
}edge[N];
void addEdge(int u,int v) {
	cnt++;
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].next = pre[u];
	pre[u] = cnt;
}
struct node {
	int u,val;
}; 
void bfs(int s) {
	queue<node> q;
	q.push({s,0});
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		int u = cur.u;
		int v = cur.val;
		for(int j = pre[u];j;j = edge[j].next) {
			int to = edge[j].to;
			if(dis[to] >= v+1) {
				dis[to] = v+1;
				dp[to]++;
				q.push({to,v+1});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cnt = 0;
		memset(pre,0,sizeof(pre));
		cin >> n >> d;
		for(int i= 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i < n;i++) {
			for(int j = i+1;j <= n;j++){
				if(abs(a[i]-a[j]) <= d) addEdge(i,j);
			}
		}
		int ans = 0;
		for(int i = 1;i < n;i++) {
			memset(dis,0x3f,sizeof(dis));
			memset(dp,0,sizeof(dp));
			bfs(i);
			for(int j = i+1;j <= n;j++) {
				if(dp[j] == 2)  {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	} 
	return 0;
} 
