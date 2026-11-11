#include<bits/stdc++.h>
using namespace std;
//O(n^2)
const int maxn = 5e5 + 5, maxm = 3e5 + 5;
int n, m, to[maxn][23], a[maxn], idx[maxn], cnt[maxn], vis[maxn];

void chk(int st) {
	for(int i = st; i <= n; i ++)
		vis[a[i]] = 0;
		
	int i = st;
	while(i <= n) {
		if(to[i][0] == i + 1) {
			if(!vis[a[i]])
				cnt[a[i]] ++;
			vis[a[i]] = 1;
		}
		i = to[i][0];
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = n; i >= 1; i --) {
		if(idx[a[i]])
			to[i][0] = idx[a[i]];
		else
			to[i][0] = i + 1;
		idx[a[i]] = i; 
	}
	for(int j = 1; j <= 19; j ++) {
		for(int i = 1; i <= n; i ++) {
			to[i][j] = to[to[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= n; i ++) {
		chk(i);
	}
	for(int i = 1; i <= m; i ++) {
		cout << cnt[i] << ' ';
	}
	return 0;
} 
