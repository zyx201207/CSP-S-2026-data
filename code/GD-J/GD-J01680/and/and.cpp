#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m;
int a[N] , mp[N];
int w[35];
int p[N] , cnt = 0;

int main () {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (int i = 1 ; i <= n ; i++) 
		for (int j = 0 ; j <= 30 ; j++)
			if ((1<<j) & a[i])
				w[j]++;
	int fl = 0 , cnt = 0;
	for (int i = 30 ; i >= 0 ; i--) {
		if (w[i] >= m) {
//			cerr << i << endl;
			if (!fl) {
				for (int j = 1 ; j <= n ; j++)
					if (!mp[j] && ((1<<i) & a[j])) 
						mp[j] = 1;
				fl = 1;
				cnt += (1 << i);
			} else {
				int tot = 0 , cnt1 = 0;
				for (int j = 1 ; j <= n ; j++)
					if (mp[j] && !((1<<i) & a[j])) {
						tot++;
					}
				for (int j = 1 ; j <= n ; j++)
					if (mp[j])
						cnt1++;
				if (cnt1 - tot >= m) {
					for (int j = 1 ; j <= n ; j++)
						if (mp[j] && !((1<<i) & a[j])) 
							mp[j] = 0;
					cnt += (1 << i);
	//				cerr << i << endl;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
} 
