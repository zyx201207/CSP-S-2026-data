/*
输入 
从小到大排序
计算前i个a[i]到第i个a[i]的差值，与m比较

如果小于m,i++
如果大于m,往回，将sum减去a[i]与a[i - 1]的差，break, 将ans = i - 1;
如果等于m,同上，不往回 , ans = i; 

输出 
*/ 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll m, ans = 0;
	cin >> n >> m;
	vector<ll> a(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	for(int i = 1;i <= n;i++){
		ll sum = 0;
		for(int j = 1;j <= i;j++) sum += abs(a[i]) - abs(a[j]);
		if(sum > m){
			sum -= abs(a[i]) - abs(a[i - 1]);
			ans = i - 1;
			break;
		} else if(sum == m){
			ans = i;
			break;
		}
	} 
	cout << ans << '\n';
	return 0;
}
