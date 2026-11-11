//#include<bits/stdc++.h>
//using namespace std;
//int x[40] , ma;
//int main() {
//	freopen("and1.in" , "r" , stdin);
//	//freopen("and.out" , "w" , stdout);
//	int n , w;
//	cin >> n >> w;
//	int a[n + 5];
//	for(int i = 1; i <= n; i++) {
//		cin >> a[i];
//		x[int(log(a[i]))]++;
//	}
//	for(int i = 39; i >= 1; i++) {
//		if(x[i] >= w){
//			ma = x[i];
//			break;
//		}
//	}
//	int math = pow(2 , ma);
//	int t = math;
//	while(1) {
//		ma = -1;
//		memset(x , 0 , sizeof(x));
//		for(int i = 1; i <= n; i++)
//			a[i] -= t , x[int(log(a[i]))] ++;
//		for(int i = 39; i >= 1; i++)
//			if(x[i] >= w){
//				ma = x[i];
//				break;
//			}
//		if(ma == -1) break;
//		t = pow(2 , ma);
//		math += t;
//	}
//	sort(a + 1 , a + n + 1 , greater<int>());
//	int ans = pow(2 , 32);
//	for(int i = 1; i <= n; i++)
//		if(a[i] < t && w > 0) ans &= a[i] , w--;
//	cout << ans;
//} 

#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , w;
	cin >> n >> w;
	int a[n + 5] , dp[w + 5];
	memset(dp , -1 , sizeof(dp));
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int k = 1; k <= n; k++) {
		for(int i = w; i >= 1; i--)
			dp[i] = max(0 , dp[i - 1] & a[k]);
	}
	sort(dp + 1 , dp + w + 1);
	cout << dp[w];
} 
