#include <bits/stdc++.h> 
using namespace std;
int a[510000];
int nxt[510000];
int pp[310000];
int sum[510000];
int ans[310000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--){
		nxt[i] = pp[a[i]];
		pp[a[i]] = i;
	}
	int x = 0;
	for (int i = 1; i <= n; i++){
		x++;
		x += sum[i];
		ans[a[i]] = x;
		if (nxt[i] != 0){
			sum[nxt[i]] += x;
			x = 0;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i];
		if (i != m){
			cout << ' ';
		}
	}
	cout << '\n';
	return 0;
}
