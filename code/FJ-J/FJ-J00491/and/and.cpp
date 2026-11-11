#include <bits/stdc++.h>
using namespace std;
long long a[200005],f[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	if(m == 1){
		sort(a+1, a+n+1);
		cout << a[n];
		return 0;
	}
	if(m == 2){
		sort(a+1,a+n+1);
		bool b = 0;
		for(long long i = n; i >= 1; i--){
			if(a[i] == a[i-1]){
				b = 1;
				cout << a[i];
				return 0;
			}
		}
		if(!b){
			long long maxn = 0;
			for(long long i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++){
					if((a[i]&a[j]) > maxn) maxn = (a[i]&a[j]);
				}
			}
			cout << maxn;
			return 0;
		}
		return 0;
	}
	if(m == n){
		long long ans = 0;
		for(long long i = 2; i <= n; i++) ans = ans & a[i];
		cout << ans << endl;
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		f[i] = a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			f[j] = max(f[j], f[j-1]&a[i]);
		}
	}
	cout << f[m];
	return 0;
} 
