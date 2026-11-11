#include<bits/stdc++.h>
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define int long long
#define pii pair<int, int>
using namespace std;

int n, m, a[200005], ans;

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	f(i, 1, n) cin >> a[i];
	dw(i, 30, 0){
		int cnt = 0;
		f(j, 1, n) cnt += (a[j] >> i) & 1;
		if(cnt >= m){
			ans |= (1 << i);
			f(j, 1, n) if(((a[j] >> i) & 1) == 0) a[j] = 0;
		}
	}
	cout << ans;
	return 0;
}

