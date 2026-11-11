#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
using ll = long long;
int n, m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i(1); i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, ans = 1;
	ll cur = 0;
	for(int r(1); r <= n; r++){
		while(cur > m){
			cur -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		if(r <= n) cur += (r - l + 1) * (a[r + 1] - a[r]);
	}
	cout << ans;
	return 0;
}
