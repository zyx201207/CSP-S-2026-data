#include<bits/stdc++.h>
using namespace std;
int n, m;
bool vis[200005];
long long a[200005];
int ans = -0x3f3f3f3f;
int d[200005];
void DFS(int pos) {
	if(pos == m + 1) {
		int sum = d[1];
		for(int i = 2;i <= m;i ++) {
			sum &= d[i];
		}
		cout << endl;
		ans = max(ans, sum);
		return;
	}
	for(int i = 1;i <= n;i ++) {
		if(!vis[i]) {
			vis[i] = 1;
			d[pos] = a[i];
			DFS(pos + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	DFS(1);
	cout << ans << endl;
	return 0;
}
