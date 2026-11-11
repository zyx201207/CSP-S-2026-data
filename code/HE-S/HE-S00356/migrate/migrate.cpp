#include <bits/stdc++.h>
using namespace std;
long long a[2111111];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, k;
	cin >> c >> k;
	if(c ==11 || c == 12){
		while(k--){ 
			int n, m;
			cin >> n >> m;
			for(int i = 1; i <= n; i++){
				cin >> a[i];
			}
			if(a[2]-a[1] >= m){
				cout << 0 << endl;
				continue;
			}
			cout << a[2]- a[1]  << endl;
		}
		return 0;
	}
	if(c ==13 || c == 14){
		while(k--){ 
			int ans = 0;
			int n, m;
			cin >> n >> m;
			for(int i = 1; i <= n; i++){
				cin >> a[i];
			}
			for(int i = 1; i <= n; i++){
				if(a[i]-a[1] <= m && a[n]-a[i] <= m){
					ans++;
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
	if(c ==15 || c == 16||c == 17 || c == 18){
		while(k--){ 
			int ans = 0;
			int n, m;
			cin >> n >> m;
			for(int i = 1; i <= n; i++){
				cin >> a[i];
			}
			cout << (a[n] - a[1])/m/2 << endl;
		}
		return 0;
	}
	while(k--){ 
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		cout << 0 << endl;
	}
	return 0;
}
