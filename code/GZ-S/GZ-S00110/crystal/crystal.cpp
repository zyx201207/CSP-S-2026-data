//GZ-S00110  张心恬  贵阳市白云区华师一学校 
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int N = 5e5 + 10;
int n, ans;
long long a[N], m, l = -1e12, r = 1e12;
map<long long, int> vis;
bool check(long long mid){
	long long sum = 0;
	int tmp;
	for (int i = 1; i <= n; i ++ ){
		if (a[i] > mid){
			break;
		}
		tmp = i;
		sum += (mid - a[i]);
		if (sum > m){
			return 0; 
		}
	}
	if (sum > m) return 0;
	return 1;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i];
		vis[a[i]] ++ ;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++ ){
		ans = max(ans, vis[a[i]]);
	}
	while (l < r){
		long long mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	for (int i = n; i >= 1; i -- ){
		if (a[i] <= l){
			ans = max(ans, i);
			break;
		}
	}
	cout << ans;
	return 0;
} 
