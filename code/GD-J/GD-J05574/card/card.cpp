#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010];
int sta[500010], top, tong[300010],ans[300010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		memset(tong, 0, sizeof(tong));
		top = 0;
		for(int j = i; j <= n; j++) {
			if(tong[a[j]] + 1 != 2) sta[++top] = a[j], tong[a[j]] += 1;
			else {
				for(; top >= 1;) if(sta[top--] == a[j]) break;
				top++;
			}
		}
		for(int j = 1; j <= top; j++) {
			ans[sta[j]]++;
		}
	}
	ans[a[n]] = n;
	for(int i=1; i<=m; i++) {
		cout << ans[i] << " ";
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
