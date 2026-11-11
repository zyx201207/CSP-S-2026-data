#include<bits/stdc++.h>
#define N 500007
#define ll long long
using namespace std;
ll n, m;
ll a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ll sum = 0, p = 1;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		if(i > 1)sum += (i - p) * (a[i] - a[i - 1]);
		while(sum > m){
			sum -= a[i] - a[p];
			p++;
		}
		ans = max(ans, i - p + 1);
	}
	cout << ans << '\n';
	return 0;
}
