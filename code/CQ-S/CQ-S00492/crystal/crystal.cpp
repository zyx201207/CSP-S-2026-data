#include <bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
bool st;
int n,m,a[maxn],suf[maxn],maxx;
bool en;
signed main(){
	#ifndef LOCAL
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	cerr << (&en-&st)/1048576.0 << "\n";
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = n;i;i--) suf[i] = suf[i+1]+a[i];
	for (int i = 1;i <= n;i++){
		int l = 1,r = i,ans = i+1;
		while (l <= r){
			int mid = l + (r - l >> 1);
			if ((i-mid+1)*a[i]-(suf[mid]-suf[i+1]) <= m) ans = mid,r = mid-1;
			else l = mid+1;
		}
//		cout << i << " " << ans << "\n";
		maxx = max(maxx,i-ans+1);
	}
	cout << maxx;
	cerr << "\n" << clock() << "\n";
	return 0;
}
