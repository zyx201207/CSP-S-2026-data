#include<bits/stdc++.h>

using namespace std;

int n, m, a[200005], b[200005];

int ans[200005];

int find(int x) {
	for(int i = 1; i <= n; i++) {
		if(b[i] == x) return i;
	}
	return 0;
} 

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while(n--) {
		int now = 0; //total-card
		for(int i = 1; i <= n; i++) {
			if(find(a[i]) != 0) {
				int w = find(a[i]);
				for(int j = w - 1; j <= n; j++) b[j] = 0;
			}
			b[now] = a[i]; 
			now++;
			b[now] = a[i];
		}
		for(int i = 1; i <= m; i++) {
			if(find(i) != 0) ans[i]++;
		}
		for(int i = 1; i <= n; i++) {
			a[i] = a[i + 1]; 
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
} 
