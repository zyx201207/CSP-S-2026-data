#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define N 500010

int n, m, a[N];
int c[N];
int num[N];
int pd[N], tp;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	if(n <= 5000) {
		for(int i = 1;i <= n;i++) {
			fill(num, num + m + 1, 0);
			tp = 0;
		
			for(int j = i;j <= n;j++) {
				if(num[a[j]] != 0) {
					for(int k = tp;k >= 1;k--) {
						num[a[pd[k]]]--;
						if(a[pd[k]] == a[j]) {
							tp = k - 1;
							break;
						}
					}
				}
				pd[++tp] = j;
				num[a[j]]++;
			}
			
			for(int j = 1;j <= m;j++) {
				c[j] += num[j]; 
			}
		}
		
		for(int i = 1;i <= m;i++) {
			cout << c[i] << " ";
		}
		cout << "\n";	
	} else if(m <= 2) {
		reverse(a + 1, a + n + 1);
		
		for(int j = 1;j <= n;j++) {
			if(num[a[j]] != 0) {
				for(int k = tp;k >= 1;k--) {
					num[a[pd[k]]]--;
					if(a[pd[k]] == a[j]) {
						tp = k - 1;
						break;
					}
				}
			}
			pd[++tp] = j;
			num[a[j]]++;
			for(int k = 1;k <= m;k++) {
				c[k] += num[k]; 
			}
		}
		
		for(int i = 1;i <= m;i++) {
			cout << c[i] << " ";
		}
		cout << "\n";	
	} else { //Ateshu
		reverse(a + 1, a + n + 1);
	
		for(int i = 1;i <= n;i++) {
			if(a[i] != a[i - 1]) {
				c[a[i]] = n - i + 1;
			}
		}
		
		for(int i = 1;i <= m;i++) {
			cout << c[i] << " ";
		}
		cout << "\n";	
	}
	return 0;
}
