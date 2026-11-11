#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
using namespace std;
const int N = 5e6 + 5;
ll a[N], sum, m, l = 1, r = 2, n, ans = 1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n)cin >> a[i];
	sort(a + 1, a + n + 1);
	sum += a[1];
	while(l <= r && r <= n){
		sum += a[r];
		if(sum + m < (r - l + 1) * a[r]){
			sum -= a[l++];
		}
		ans = max(r - l + 1, ans);
		r++;
	}
	cout << ans;
	return 0;
}
