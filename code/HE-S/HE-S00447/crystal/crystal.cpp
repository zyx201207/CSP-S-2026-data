#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n , m , a[N];
long long cnt[N] , ans , maxn , k;

bool cmp(long long x , long long y) {
	return x > y;
}

int main() {
	
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	cin >> n >> m;
	bool fg = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] , cnt[a[i]]++;
		if(a[i] >= 0) fg = 1;
	}
	for(int i = 1; i <= n; i++) maxn = max(maxn , cnt[a[i]]);
	if(m == 0) {
		cout << maxn;
		return 0;
	}
	if(fg == 1) {
		sort(a + 1 , a + n + 1);
		for(int i = 1; i <= n; i++) {
			if(n % 2 == 0) {
				if(cnt[a[n / 2]] == maxn) {
					k = a[n / 2];
					break;
				}
				else if(cnt[a[i]] == maxn) {
					k = a[i];
					break;
				}
			}
			else if(n % 2 == 1) {
				if(cnt[a[n / 2 + 1]] == maxn) {
					k = a[n / 2 + 1];
					break;
				}
				else if(cnt[a[i]] == maxn) {
					k = a[i];
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			if(a[i] < k && m >= k - a[i]) {
				ans++;
				m -= k - a[i];
			}
		}
	}
	else {
		sort(a + 1 , a + n + 1 , cmp);
		for(int i = 1; i <= n; i++) {
			if(a[i] < a[1] && m >= a[1] - a[i]) {
				ans++;
				m -= a[1] - a[i];
			}
		}
	}
	cout << ans + maxn;
	
	return 0;
} 

/*
CCF I love you!!!
RP++ , AC++ , WA-- , TLE--
sto CCF orz
*/

