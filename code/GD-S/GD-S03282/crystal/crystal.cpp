//记得Long long 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
long long a[MAXN];
long long m;
int n; 
int maxans = 0;
long long solve(long long k){
	int l = 1, r = n;
	long long sum = 0, ans = 0;
	while (l+1 < r){
		//cout << l << " " << r << endl;
		int mid = (l + r) >> 1;
		if (k < a[mid]){
			r = mid;
		} else if (k > a[mid]){
			l = mid;
		} else if (a[mid] == k){
			if (mid != n) l = mid, r = mid+1;
			else l = mid-1, r = mid;
			break;
		}
	} 
	//printf("l:%d, r:%d ", l, r);	
	for (int i = r; i >= 1; i--){
		if (a[i] > k) continue;
		sum += (k - a[i]);
		if (sum <= m){
			ans ++;
		}
	} 
	//cout << ans << endl;
	if (ans >= maxans){
		maxans = ans;
		//printf("ans:%d k:%lld sum:%lld\n", maxans, k, sum);
	}
	return ans;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	//for (int i = 1; i <= n; i++) cout << a[i] << " ";
	/*long long h = 0;
	for (int i = 1; i <= n; i++){
		h += abs(a[i]-a[1]);
	}
	cout << h;*/
	if (a[n] >= 1e12){
		for (int i = 1; i <= n; i++){
			solve(a[i]);
		}
		cout << maxans;
		return 0;
	}
	for (long long i = a[1]; i <= a[n]; i++){
		//cout << i << " ";
		solve(i);
	} 
	cout << maxans;
	return 0;
} 
/*
找到一个基准线 k, 当为k时计算所有的距离到k的距离，然后取最小值 
二分找？ 

猜测，在a[i]为基准线时一定满足最优解
证明：对于任意一组数据 a1, a2 …… an
如果存在 ai 与 ai+1 中有一个最优解
 
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 49
1 3 20 21 22
*/
