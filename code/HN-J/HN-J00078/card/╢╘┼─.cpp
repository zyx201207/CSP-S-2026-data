/*
ÕâÊÇ¶ÔÅÄ 
*/ 
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;
int n, m, a[N], vis[N], ans[N];

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("cardp.in", "r", stdin);
	freopen("cardp.out", "w", stdout);
	cin >> n >> m; // fc card.out cardp.out 
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			bool flag = 0;
			for(int k = i; k < j; k++) {
				if(vis[k]) continue; 
				if(flag || a[k] == a[j]) {
					vis[k] = 1;
					flag = 1;
				}
			}
		}
		for(int j = i; j <= n; j++) {
			if(!vis[j]) ans[a[j]]++;
			vis[j] = 0;
		}
	} 
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
} 
