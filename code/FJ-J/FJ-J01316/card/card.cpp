#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 5 * 1e5 + 5;
int a[maxn];
int vis[maxn];
int t[maxn];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]] = 1;
	}
	for(int i = 1; i <= n; i++) { //ÂÖÊý
		for(int o = i; o <= n; o++) {
			vis[a[o]] = 1;
		}
		if(i == n) goto b;
		for(int j = i; j <= n; j++) {
			for(int k = i; k < j; k++) {
				if(a[k] == a[j]) {
					for(int p = k; p < j; p++) {
						vis[p] = 0;
						goto a;
					}
				}
				
			}
			a:;
			
		}
		b:;
		for(int q = i; q <= n; q++) {
			if(vis[q] == 1)  {
				t[a[q]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
