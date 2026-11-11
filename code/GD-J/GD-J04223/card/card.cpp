#include <bits/stdc++.h>
using namespace std;
int a[1236787];
int cnt[1000][1000];
int main() { 
	freopen("card.in", "s", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++ ) {
			cnt[i][j] = a[j];
			for(int u = i; u <= j - 1; u++){
				if(cnt[i][u] == a[j])
					for(int s = i; s <= j - 1; s++)cnt[i][s] = -1;
			}
		}
	}
	
	for(int u = 1; u <= m; u++) {
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++ ) {
				if(cnt[i][j] == u)ans++;
			}
		}
		cout << ans <<" ";
	}
	return 0;
}//为何不让运行 
