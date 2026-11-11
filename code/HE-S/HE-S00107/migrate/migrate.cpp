#include <bits/stdc++.h>
#define int long long
const int MAXN = 20005;
using namespace std;
int c,t,n,d,x[MAXN],cnt[MAXN],min1[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		int ans = 0;
		cin >> n >> d;
		for (int i = 1;i<=n;i++){
			cin >> x[i];
		}
		for (int zong = 1;zong<=n;zong++){
			for (int i = 1;i<=n;i++){
				cnt[i] = 0;
				min1[i] = 1e18;
			}
			min1[zong] = 0;
			cnt[zong] = 1;
			for (int i = zong;i<=n;i++){
				for (int j = i-1;j>=zong;j--){
					if (x[i] - x[j] > d){
						break;
					}
					if (min1[i] > min1[j] + 1){
						min1[i] = min1[j] + 1;
						cnt[i] = 1;
					}else if (min1[i] == min1[j] + 1){
						cnt[i]++; 
					} 
				}
				if (cnt[i] == 2){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
