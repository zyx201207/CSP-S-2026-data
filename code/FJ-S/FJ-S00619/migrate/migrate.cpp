#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
const int N = 2000005;
struct node {
	int dis,u;
	
	bool operator>(const node& a) const {
		return dis>a.dis;
	}
};
int n;
ll d;
ll runcnt;
ll x[N];
int cnt[N];
int dis[N];
bool vis[N];
priority_queue<node,vector<node>,greater<node>> q;
void dijkstra(int s) {
	for (int i=1; i<=n; i++) {
		dis[i]=0x3f3f3f3f;
		cnt[i]=0;
	}
	
	dis[s]=0;
	q.push({0,s});
	while (!q.empty()) {
		int u=q.top().u;
		q.pop();
		for (int i=u+1; i<=n; i++) {
			runcnt++;
			if (x[i]-x[u]<=d) {
				if (dis[i]>=dis[u]+1) {
					dis[i]=dis[u]+1;
					cnt[i]++;
					q.push({dis[i],i});
				}
			} else {
				break;
			}
		}
	} 
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int C,T;
	cin>>C>>T;
	while (T--) {
		cin>>n>>d;
		for (int i=1; i<=n; i++)
			cin>>x[i];
		int ans=0;
		for (int i=1; i<n; i++) {
			dijkstra(i);

			for (int j=i+1; j<=n; j++) {
				if (cnt[j]==2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
