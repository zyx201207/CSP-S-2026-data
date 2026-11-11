#include<bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
//
//
//
using namespace std;
inline int read() {
	int sum = 0, f = 0;
	char c = getchar();
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) sum = (sum<<1) + (sum << 3) + c - 48, c = getchar();
	return f ? -sum: sum;
}
const int MX = 5e5 + 10;
int a[MX], sum[MX];
int n, m;
int check(int x) {
	int l = 1, r = x, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1ll;
		if((a[x] * (x - mid + 1) - (sum[x] - sum[mid - 1])) <= m) ans = max(ans, x - mid + 1), r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(), m = read();
	FOR(i,1,n) a[i] = read();
	sort(a + 1, a + n + 1);
	FOR(i,1,n) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	FOR(i,1,n) {
		ans = max(ans, check(i));
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/

