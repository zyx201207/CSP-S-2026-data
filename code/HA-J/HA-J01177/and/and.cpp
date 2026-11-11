#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
vector<int> a[30];
bool vis[200005];
int gjr[200005];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		int x;
		cin >> gjr[i];
		x = gjr[i];
		for(int j = 30;j >= 0;j--) {
			if((1ll << j) <= x) {
				a[j].push_back(i);
				x -= (1ll << j);
			}
		}
	}
	int answ = 0;
	for(int i = 30;i >= 0;i--) {
		int cach = 0;
		for(int j = 0;j < a[i].size();j++) {
			if(vis[a[i][j]] == 0) cach++;
		}
		if(cach < m) continue;
		answ += (1ll << i);
		for(int j = 1;j <= n;j++) {
			if(!(gjr[j] & (1ll << i))) vis[j] = 1;
		}
	}
	cout << answ;
	return 0;
}
