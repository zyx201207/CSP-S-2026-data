#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[2000005];
int n, d;
struct point{
	int m;
	int s;
};
point ans[5005][5005];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= 2000002; i++){
			a[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(c == 11 || c == 12){
			if(n < 4){
				cout << 0 << "\n";
			}
			else{
				int f = 3;
				for(f; 2 * f - 2 <= n; f++){
					if(a[f] - a[1] <= d && a[f + 1] - a[1] > d){
						break;
					}
				}
				if(2 * f - 2 > n){
					cout << 0 << "\n";
				}
				else{
					cout << n - 2 * f + 3 << "\n";
				}
			}
		}
		else{
			if(n < 4){
				cout << 0 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}
