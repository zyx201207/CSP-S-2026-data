#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
int n, m, ans = 0;
ll a[maxn];
__int128 s[maxn];
__int128 tousu = 1;
//s[i]表示1~i所有数字都加到数组最大值所需操作次数 
bool spA = true; //特殊性质A的部分分（15） 
bool spB = true; //特殊性质B的部分分（15） 
bool check(int mid){
	for(int i = 1;i + mid - 1 <= n && i <= n;i++){
		int d = a[n] - a[i+mid-1];
		if(s[i+mid-1] - s[i-1] - tousu * mid * d <= m) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != a[i-1]) spA = false;
	}
	if(spA){
		cout << n; //m次操作1次也不用 
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		if(a[i+1] - a[i] != 1) spB = false;
		s[i] = s[i-1] + (a[n] - a[i]);
	}
	if(spB){
		int l = 1, r = n, mid;
		while(l <= r){
			mid = (l + r) >> 1;
			if((1 + mid) * mid / 2 <= m){
				l = mid + 1;
				ans = max(ans, mid);
			}else r = mid - 1;
		}
		cout << ans;
		return 0;
	}
	int l = 1, r = n, mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = max(ans, mid);
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
} 

