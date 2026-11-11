#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
#define int long long
#define pb push_back
const int N = 505, M = 5e5 + 5;



int c, n, m, d, q;
int w[M];

struct node{
	int v, w;
	bool operator < (const node & other) const {
		return w > other.w;
	}
};

vector<node> e[N];

int dis[M];
bool f[N];

int dij(int sta, int en) {
	memset(dis, 0x3f, sizeof dis);
	memset(f, 0, sizeof f);
	priority_queue<node> pq;
	pq.push({sta, 0});
	dis[sta] = 0;
	while(!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if(f[now.v]) continue;
		if(now.v == en) return dis[en];
		f[now.v] = 1;
		for(node nxt : e[now.v]) {
			if(dis[nxt.v] > dis[now.v] + nxt.w) {
				dis[nxt.v] = dis[now.v] + nxt.w;
				pq.push({nxt.v, dis[nxt.v]});
			}
		}
	}
	return dis[en];
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	fo(i, 1, m) cin >> w[i];
	fo(i, 1, n) {
		int kk;
		cin >> kk;
		vector<int> ka(kk + 1), kb(kk + 1);
		fo(j, 1, kk) cin >> ka[j] >> kb[j];
		fo(j, 1, kk) {
			fo(k, j + 1, kk) {
				e[ka[j]].pb({ka[k], kb[j] + kb[k]});
				e[ka[k]].pb({ka[j], kb[j] + kb[k]});
			}
		}
	}
	while(q--) {
		int ll, rr;
		cin >> ll >> rr;
		cout << w[ll] + dij(ll, rr) + w[rr] << '\n';
	}
 	return 0;
}
/*
 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
 * 
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
