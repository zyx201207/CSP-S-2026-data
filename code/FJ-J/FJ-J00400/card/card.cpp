#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int l = 0;
int a[N];
int vis[N];
int stk[N];
int ton[M];
void push(int x) {
	stk[++l] = x;
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) {
		l = 0;
		for(int j=1;j<=n;j++) vis[j] = 0;
		for(int j=i;j<=n;j++) {
			if(vis[a[j]] == 0) {
				push(a[j]);
				vis[a[j]] = 1;
				continue;
			}
			for(int k=1;k<=l;k++) {
				if(stk[k] == a[j]) {
					for(int c=k+1;c<=l;c++) vis[stk[c]] = 0, stk[c] = 0;
					l = k;
					for(int c=1;c<=l;c++) vis[stk[c]] = 1;
					break;
				}
			}
		}
		for(int j=1;j<=l;j++) ton[stk[j]]++; 
	}
	for(int i=1;i<=m;i++) cout << ton[i] << ' ';
	return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1

3 1
1 
2 1
1
3 1
2 1
3 1
1
2 1
1*/
