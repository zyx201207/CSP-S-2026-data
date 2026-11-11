#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], b[N], vis[N];
void xiugai(int l, int r) {
	for (int i = l; i < r; i++) {
		b[i] = 0;
	}
}
void solve(int l) {
	for (int i = l; i <= n; i++) {
		for (int j = l; j < i; j++) {
			if (b[j] == b[i]) {
				xiugai(j, i);
			}
		}
	}
	for (int i = l; i <= n; i++) {
		if (b[i] != 0) {
			vis[b[i]]++;
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1;
	int x = n;
	while(x--) {
		for (int i = l; i <= n; i++) {
			b[i] = a[i];
		}
		solve(l);
		l++;
		
	}
	for (int i = 1; i <= m; i++) {
		cout << vis[i] << " ";
	}
	return 0;
}
