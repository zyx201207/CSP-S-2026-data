#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, m, flag = 1, a[500005], mp[500005], mp1[500005], mp2[500005], lst[500005];

int main() {
	
//	freopen("1.in", "r", stdin);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (LL i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (LL i = 1; i <= n; i ++) {
		if (a[i] < a[i - 1]) {
			flag = 0;
			break;
		}
	}
	
	if (flag) {
		for (LL i = 1; i <= n; i ++) {
			mp[a[i]] ++;
		}
		for (LL i = 1; i <= m; i ++) {
			mp1[i] = mp1[i - 1] + mp[i];
			cout << mp1[i] << ' ';
		}
	} else {
		for (LL k = 1; k <= n; k ++) {
			for (LL i = 1; i <= m; i ++) 
				lst[i] = -1;
			for (LL i = 1; i <= n; i ++) 
				mp[i] = mp1[i] = 0;
			for (LL i = k; i <= n; i ++) {
				if (lst[a[i]] != -1) {
					for (LL j = k; j <= i; j ++) {
						mp1[j] = mp1[j - 1] + mp[j];
					}
					if (mp1[lst[a[i]]])
						{ lst[a[i]] = i; continue; } 
					mp[lst[a[i]]] ++;
					mp[i] --;
					for (LL j = k; j <= i; j ++) {
						mp1[j] = 0;
					}
				}
				lst[a[i]] = i;
			}
			for (LL i = k; i <= n; i ++)
				mp1[i] = 0;
			for (LL i = k; i <= n; i ++) {
				mp1[i] = mp1[i - 1] + mp[i];
				if (mp1[i] == 0)
					mp2[a[i]] ++;
			}		
		}
		
		for (LL i = 1; i <= m; i ++) 
			cout << mp2[i] << ' ';
	}

	return 0;
}
