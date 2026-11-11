#include<bits/stdc++.h>
using namespace std;
struct pos{
	long long p;
	long long v;
};
struct node{
	long long p;
	long long q;
	long long v;
};
bool operator>(node a1, node a2) {
	return a1.v < a2.v;
}
bool vis_st[500005];
bool vis_lt[505];
long long s[500005];
long long dis[500005];
long long k[500005];
long long C, n, m, d, q;
long long let, rit, ans;
vector<vector<pos> > a;
vector<vector<pos> > b;
void dfs(long long st, long long lt, long long sum) {
//	cout << st << " " << lt << " " << sum << endl;
	if (st == rit) {
		long long cnt = 0;
		if (lt != 0) {
			for (long long i = 0; i < a[lt].size(); i++) {
				long long fp = a[lt][i].p;
				if (fp == st) {
					cnt = a[lt][i].v;
				}
			}	
		}
//		cout << sum + cnt + s[st] << endl;
//		cout << endl;
		ans = min(ans, sum + cnt + s[st]);
	} else {
		long long cnt = 0;
		if (lt != 0) {
			for (long long i = 0; i < a[lt].size(); i++) {
				long long fp = a[lt][i].p;
				if (vis_st[fp] == 0) {
					vis_st[fp] = 1;
					dfs(fp, lt, sum);
					vis_st[fp] = 0;
				}
				if (fp == st) {
					cnt = a[lt][i].v;
				}
			}	
		}
		
		for (long long i = 0; i < b[st].size(); i++) {
			long long fp = b[st][i].p;
			if (vis_lt[fp] == 0) {
				vis_lt[fp] = 1;
				dfs(st, fp, sum + cnt + b[st][i].v);
				vis_lt[fp] = 0;
			}
		}
	}
}
void dijstra() {
	memset(dis, 0x7f, sizeof(dis));
	priority_queue<node, vector<node>, greater<node> > pq;
	pq.push({let, 0, s[let]});
	dis[let] = s[let];
	while(!pq.empty()) {
		node temp = pq.top();
		pq.pop();
		//	cout << temp.v; 
		if (temp.v > dis[temp.p]) continue;
		long long cnt = 0;
		long long np = temp.p, nf = temp.q, sum = temp.v;
		if (nf != 0) {
			for (long long i = 0; i < a[nf].size(); i++) {
				long long fp = a[nf][i].p;
				if (dis[fp] > sum) {
					dis[fp] = sum;
					pq.push({fp, nf, dis[fp]});
				}
				if (fp == np) {
					cnt = a[nf][i].v;
				}
			}	
		}
		cout << cnt << endl;
		for (long long i = 0; i < b[np].size(); i++) {
			for (long long j = 0; j < a[b[np][i].p].size(); j++) {
				long long fp = a[b[np][i].p][j].p;
				if (dis[fp] > sum + cnt + b[np][i].v) {
					dis[fp] = sum + cnt + b[np][i].v;
					pq.push({fp, b[np][i].p, dis[fp]});
				}
			}
		}	
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) {
		cin >> s[i];
	}
	a.resize(n + 1);
	b.resize(m + 1);
	for (long long l = 1; l <= n; l++) {
		cin >> k[l];
		a[l].resize(k[l]);
		for (long long i = 0; i < a[l].size(); i++) {
			cin >> a[l][i].p >> a[l][i].v;
			b[a[l][i].p].push_back({l, a[l][i].v});
		}
	}
	for (long long l = 1; l <= q; l++) {
		cin >> let >> rit;
		if (C <= 3) {
			ans = 1e18;
			vis_st[let] = 1;
			dfs(let, 0, s[let]);
			cout << ans << endl;
			memset(vis_st, 0, sizeof(vis_st));
			memset(vis_lt, 0, sizeof(vis_lt));
		} else {
			dijstra();
			cout << dis[rit] + s[rit] << endl;
		}
	}
	return 0;
}
