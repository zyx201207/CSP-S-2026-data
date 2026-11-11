#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
using namespace std;


const int N = 5e5 + 5, M = 505, O = 1e5 + 5;

vector <int> a[M], t[M];
int k[M], w[N], c, n, m, d, q;

namespace Sub1 {
	const long long K = 1e15;
	vector <pair <int, int> > arr[N];
	vector <pair <int, long long> > road[N];
	long long dis[M][M], rch[M][M];
	bool vis[M][M];
	
	void dij (int st) {
		priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > q;
		int now;
		rep (i, 1, n) dis[st][i] = K;
		q.push ({0, st}), dis[st][st] = 0;
		while (!q.empty ()) {
			now = q.top ().second, q.pop ();
			if (vis[st][now] == true) continue;
			vis[st][now] = true;
			for (pair <int, long long> i : road[now]){
				if (dis[st][now] + i.second < dis[st][i.first]) dis[st][i.first] = i.second + dis[st][now], q.push ({dis[st][i.first], i.first});
			}
		}
	}
	
	int work () {
		int st, ed, tp, l, r;
		long long ret;
		//cerr << "sp1" << endl;
		rep (i, 1, n) {
			tp = a[i].size ();
			rep (j, 0, tp - 1) arr[a[i][j]].push_back ({i, t[i][j]});
		} 
		//cerr << "sp1" << endl;
		rep (i, 1, n) rep (j, 1, n) rch[i][j] = K;
		rep (i, 1, m) {
			tp = arr[i].size ();
			rep (j, 0, tp - 1) {
				rep (k, 0, tp - 1) {
					if (j != k) {
						l = min (arr[i][j].first, arr[i][k].first), r = max(arr[i][j].first, arr[i][k].first);
						rch[l][r] = min(rch[l][r], 0LL + arr[i][j].second + arr[i][k].second);
					}
				}
			}
		}
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				if (rch[i][j] != K) road[i].push_back ({j, rch[i][j]}), road[j].push_back ({i, rch[i][j]});
			}
		}
		//cerr << "sp1" << endl;
		rep (i, 1, n) dij (i);
		//cerr << "sp1" << endl;
		rep (i, 1, q) {
			//cerr << "sp"
			cin >> st >> ed, ret = LLONG_MAX;
			//cerr << st << " " << ed << " " << arr[st].size () << " " << arr[ed].size () << endl;
			for (pair <int, int> j : arr[st]) {
				for (pair <int, int> l : arr[ed]) {
					//cerr << " " << j.first << " " << l.first << " " << j.second << " " << l.second;
					ret = min (ret, 0LL + w[st] + w[ed] + j.second + l.second + 1LL * dis[j.first][l.first]);
				}
			}
			cout << ret << endl;
		}
		return 0;
	}
}

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int ina, intt;
	cin >> c >> n >> m >> d >> q;
	rep (i, 1, m) cin >> w[i];
	rep (i, 1, n) {
		cin >> k[i];
		rep (j, 1, k[i]) {
			cin >> ina >> intt, a[i].push_back (ina), t[i].push_back (intt);
			//if (ina == 5490) cerr << "sp10" << endl;
		}
	}
	return Sub1 :: work ();
}
