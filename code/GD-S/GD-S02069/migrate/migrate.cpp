#include <iostream>
#include <map>
using ll = long long;
using namespace std;
constexpr int N = 2e6+5;
int n,d;
ll x[N];
map<pair<int,int>,int> dis;
int calcdis(int i,int j) {
	auto p = make_pair(i,j);
	if (dis.count(p)) return dis[p];
	if (i == j) return dis[p] = 0;
	if (x[j] - x[i] <= d) return dis[p] = 1;
	if (x[i + 1] - x[i] > d) return dis[p] = -1;
	for (int k = i + 2; k <= j; ++k) {
		if (x[k] - x[i] > d) {
			if (calcdis(k-1,j) != -1) return dis[p] = 1 + calcdis(k-1,j);
			return dis[p] = -1;
		}
	}
	return dis[p] = 1;
}
int cnt;
int dist;
void findroutes(int i,int j,int c) {
	if (i == j) {
		if (c == dist) ++cnt;
		return ;
	}
	if (cnt > 2) return ;
	for (int k = i + 1; k <= j; ++k) {
		if (x[k] - x[i] > d) break;
		findroutes(k,j,c + 1);
		if (cnt > 2) return ;
	}
	if (cnt > 2) return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		int ans = 0;
		dis.clear();
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				dist = calcdis(i,j);
//				cout << "the minimum distance from " << i << " to " << j << " is:" << dist << endl;
				cnt = 0;
				findroutes(i,j,0);
				if (cnt == 2) ++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
