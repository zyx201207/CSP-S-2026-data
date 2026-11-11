#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010], ans = INT_MIN, xz[200010];
struct how_many {
	vector<int>val;
} b[20];
bool used[200010];
void dfs(int size_, int from, int chose) {
	if(chose == m) {
		long long t = xz[0];
		for(int i = 1; i < m; i++) t = (t & xz[i]);
		ans = max(ans, t);
		return;
	}
	for(int i = 0; i < size_; i++) {
		if(!used[i]) {
			used[i] = true;
			xz[i] = b[from].val[i];
			dfs(size_, from, chose + 1);
			xz[i] = 0;
			used[i] = false;
		}
	}
	return;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
		int t = a[i], index = 1;
		while(t) {
			if(t % 2 == 1) b[index].val.push_back(a[i]);
			t /= 2;
			index++;
		}
	}
	if(m==1) {
		for(int i = 1; i <= n; i++) ans=max(ans, a[i]);
		cout << ans;
		fclose(stdin), fclose(stdout);
		return 0;
	} else if(m == n) {
		ans = a[1];
		for(int i = 2; i <= n; i++) ans = (ans & a[i]);
		cout << ans;
		fclose(stdin), fclose(stdout);
		return 0;
	}
	for(int i = 19; i >= 0; i--) {
		if(b[i].val.size() > m) {
			dfs(b[i].val.size(), i, 0);
			break;
		} else if(b[i].val.size() == m) {
			long long t = b[i].val[0];
			for(int j = 1; j < m; j++) t = (t & b[i].val[j]);
			ans = max(ans, t);
			break;
		}
	}
	cout << ans;
	fclose(stdin), fclose(stdout);
	return 0;
}
