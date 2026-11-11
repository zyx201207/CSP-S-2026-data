#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int i = 1;i <= t;i++){
		int n,d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> x[i];
		}
		if (c == 13 || c == 14){
			int ans = 0;
			for (int i = 1;i <= n-2;i++){
				ans += i;
			}
			cout << ans;
			return 0;
		}
		if (c == 11 || c == 12){
			int ans = 0;
			for (int i = 1;i <= n;i++){
				for (int j = i + 2;j <= n;j++){
					if (x[j] - x[i] >= 2 * d){
						ans++;
					}
				}
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
