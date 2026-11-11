#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (n == m){
		long long f = a[1];
		for (int i = 2;i <= n;i++){
			f &= a[i];
		}
		cout << f;
		return 0;
	}
	if (m == 1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	if (m == 2){
		long long maxn = -1;
		for (int i = 1;i <= n-1;i++){
			for (int j = i+1;j <= n;j++){
				maxn = max(maxn,a[i]&a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 3){
		long long maxn = -1;
		for (int i = 1;i <= n-2;i++){
			for (int j = i+1;j <= n-1;j++){
				for (int k = j+1;k <= n;k++){
					maxn = max(maxn,a[i]&a[j]&a[k]);
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 4){
		long long maxn = -1;
		for (int i = 1;i <= n-3;i++){
			for (int j = i+1;j <= n-2;j++){
				for (int k = j+1;k <= n-1;k++){
					for (int l = k+1;l <= n;l++){
						maxn = max(maxn,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 5){
		long long maxn = -1;
		for (int i = 1;i <= n-4;i++){
			for (int j = i+1;j <= n-3;j++){
				for (int k = j+1;k <= n-2;k++){
					for (int l = k+1;l <= n-1;l++){
						for (int o = l+1;o <= n;o++){
							maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]);
						}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == n-1){
		long long maxn = -1;
		for (int i = 1;i <= n;i++){
			long long f = 2e21-1;
			for (int j = 1;j <= n;j++){
				if (j != i) f &= a[j];
			}
			maxn = max(maxn,f);
		}
		cout << maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	cout << a[n];
}
