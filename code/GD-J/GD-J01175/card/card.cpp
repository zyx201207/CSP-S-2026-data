#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5 , M = 3e5 + 5;
int a[N] , b[N] , cnt[M];
int n , m , c[N] , v[M];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out", "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) memset(cnt , 0 , sizeof cnt);
		if (i != 1) memset(v , 0 , sizeof v);
		int ii = i , j = i , q = n - i + 1;
		while (q--) {
			if (!cnt[a[j]]) {
				cnt[a[ii]]++;
				v[a[ii]] = j;
			} else {
				for (int k = 1; k <= m; k++) {
					if (v[k] > v[a[ii]]) {
						v[k] = 0;
						cnt[k] = 0;
					} 
				}
				j = v[a[ii]];
			}
			ii++;
			j++;
		}
		for (int j = 1; j <= m; j++) {
			if (cnt[j]) c[j]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << ' ';
	}
	return 0;
}
