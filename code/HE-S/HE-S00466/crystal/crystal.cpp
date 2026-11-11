//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//
//int n , m , a[500010];
//bool check(int x){
//	int cnt = 0 , sum = 0;
//	for(int i = x ; i >= 1 ; i--){
//		int t = a[x] - a[i];
//		if(sum + t > m) break;
//		sum += t , cnt++;
//	}return cnt;
//}
//
//signed main(){
//	freopen("crystal.in" , "r" , stdin);
//	freopen("crystal.out" , "w" , stdout);
//	cin >> n >> m;
//	int l = 1 , r = n , cnt = 0 , zd = 0;
//	for(int i = 1 ; i <= n ; i++) cin >> a[i];
//	sort(a + 1 , a + n + 1);
//	while(l <= r){
//		int mid = (l + r) / 2;
//		if(check(mid)) l = mid + 1;
//		else r = mid - 1;
//		cout << ++cnt << " : " << mid << endl;
//	}int ans = 0 , ansi;
//	for(int i = 1 ; i <= n ; i++) if(a[i] <= ansi) ans++;
//	cout << ans;
//	return 0;
//}
// 
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n , m , a[500010] , zd = 0;
int q[500010] , hd = 1 , tl = 1;

signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	int sum = 0 , now = a[1]; q[tl++] = 1;
	for(int i = 2 ; i <= n ; i++){
		sum += (a[i] - now) * (tl - hd);
		while(sum > m && hd <= tl)
			sum -= (a[i] - a[q[hd++]]);
		q[tl++] = i; now = a[i];
		zd = max(zd , (tl - hd));
	}cout << zd;
	return 0;
}
 
