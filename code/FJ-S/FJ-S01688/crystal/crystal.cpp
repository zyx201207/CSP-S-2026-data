#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 1e6 + 5; 
ll n, m, a[N], pre[N], ans = 1;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	pre[0] = 0;
	for(int i = 1; i <= n ; i ++)
		pre[i] = pre[i - 1] + a[i];
	ll l = 1, cnt = 0;// l -> i
	for(int i = 1; i <= n ; i ++){
		while(l <= i && a[i] * (i - l) - (pre[i - 1] - pre[l - 1]) > m){
			l ++;
			cnt --;
		}
		cnt ++;
		ans = max(ans, cnt);	
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
