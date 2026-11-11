#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n, sum, l, r, ans, a[N], b[N];
char ch[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> ch[i];
		a[i] += a[i-1];
		b[i] = a[i-1]+1;
		sum += a[i]-a[i-1];
	}
	l = 1, r = sum;
	while(l <= r){
		int d = 0, f = 1;
		int ls = upper_bound(b+1, b+n+1, l)-b-1;
		int rs = lower_bound(a+1, a+n+1, r)-a;
		int disl = abs(a[ls]-l)+1, disr = abs(r-b[rs])+1;
		if(ch[ls] != ch[rs]) f = 0;
		if(disl <= disr) d = disl;
		else d = disr;
		if(!f) ans += d;
		l += d, r -= d;
	}
	cout << ans;
	return 0;
}
