#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 5010;
ll a[N];
int n;
ll d;

int e[N << 1],ne[N << 1],h[N],idx;
pii all[N];
void adde(int a,int b,int c) {
	e[++idx] = b,ne[idx] = h[a],h[a] = idx;
}
queue<int> q;
bool vis[N];
int cnt[N];
int dist[N];
void dijsktra(int s) {
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(make_pair(0,s));
	vis[s] = true;
	cnt[s] = 1;
	dist[s] = 0;
	while(!q.empty()) {
		pii t = q.top();
		q.pop();
		int u = t.second,dis = t.first;
		vis[u] = true;
		for(int i = h[u];i;i = ne[i]) {
			int v = e[i];
			if(vis[v]) continue;
			if(dis + 1 < dist[v]) {
				dist[v] = dis + 1;
				cnt[v] = 1;
				q.push(make_pair(dist[v],v));
			} else if(dis + 1 == dist[v]) {
//				cout << v << '\n';
				cnt[v]++;
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--) {
		ll ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++) {
			int l = 1,r = i;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(a[i] - a[mid] <= d) {
					all[i].first = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			l = i,r = n;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(a[mid] - a[i] <= d) {
					all[i].second = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
		}
		for(int i = 1;i <= n;i++) h[i] = 0;
		idx = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = all[i].first;j <= all[i].second;j++) {
				if(i == j) continue;
				adde(i,j,1);
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) vis[j] = false;
			for(int j = 1;j <= n;j++) dist[j] = 0x3f3f3f3f;
			for(int j = 1;j <= n;j++) cnt[j] = 0;
			dijsktra(i);
//			for(int j = i + 1;j <= n;j++)
//					cout << i << ' ' << j << ' ' << dist[j] << ' ' << cnt[j] << '\n';
			for(int j = i + 1;j <= n;j++) {
				if(cnt[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983


*/