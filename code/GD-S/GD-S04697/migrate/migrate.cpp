#include <iostream>
#include <cstdio>
using namespace std;
int n, m, t, a[200005], num, ans;
void dfs(int start, int end) {
	if(start == end) {
		num++;
		return;
	}
	for(int i = start + 1; i <= end; i++) {
		if(a[i] > a[start] + m) {
			break;
		}
		dfs(i, end);
		if(num > 2) {
			return;
		}
	}
	return;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 4; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				num = 0;
				dfs(j, i);
				if(num == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
