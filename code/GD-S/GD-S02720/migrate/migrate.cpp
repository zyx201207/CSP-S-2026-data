#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[2000001];

signed main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	int id,n;
	cin >> id >> n;
	
	while (n --){
		int n,d;
		cin >> n >> d;
		
		for (int i = 1;i <= n;i ++){
			cin >> a[i];
		}
		
		sort (a + 1,a + n + 1);
		
		int ans = 0;
		int cnt = 2 * d - 1;
		for (int i = 1;i <= n;i ++){
			for (int j = i + d;a[j] <= a[i] + cnt && j <= n;j ++){
				int sum = 0;
				for (int k = i;k <= j;k ++){
					sum += (a[k] - a[i] <= d && a[j] - a[k] <= d);
				}
				if (sum == 2) ans ++;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
