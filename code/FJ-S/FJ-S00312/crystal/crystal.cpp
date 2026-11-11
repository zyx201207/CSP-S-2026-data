#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,m,a[N],x,ans,mx = -1e9,mn = 1e9;
int main(){
	// freopen("crystal.in","r",stdin);
	// freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
	}
	if (mx > 1e5 || mn < -1e5){
		x = a[2] - a[1];
		long long cnt = 1;
		while (m > 0){
			ans++;
			m -= x * cnt;
			cnt++;
		}
		cout << ans;
	}
	else{
		for (int i = mn;i <= mx;i++){
			long long sum = 0,t = 0;
			bool flag = 1;
			for (int j = 1;j <= n;j++){
				if (a[j] <= i){
					sum += i - a[j];
					t++;
					if (sum > m){
						flag = 0;
						break;
					}
				}
			}
			if (sum <= m && flag){
				ans = max(ans,t);
			}
		}
		cout << ans;
	}
	return 0;
}
