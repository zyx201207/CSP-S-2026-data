#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500010];
long long ans[300010];
int last[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		last[a[i]] = i;
	}
	for(int i = n; i >= 1; i--) {
		int j = i;
		while(j <= n) {
			ans[a[j]]++;
			j = last[a[j]] + 1;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
