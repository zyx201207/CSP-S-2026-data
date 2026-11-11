#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5*1e5+5;
int n,m,c[MAXN],cnt[MAXN],a[MAXN],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int l = 1;
	for (int i = 1;i<=n;i++){
		c[i] = c[i-1] + (a[i] - a[i-1]) * cnt[i-1];
		cnt[i] = cnt[i-1]+1;
		while (l <= i&&c[i] > m){
			c[i] -= a[i] - a[l];
			l++;
			cnt[i]--;
		}
	}
	for (int i = 1;i<=n;i++){
		ans = max(ans,cnt[i]);
	}
	cout << ans;
	return 0;
}
