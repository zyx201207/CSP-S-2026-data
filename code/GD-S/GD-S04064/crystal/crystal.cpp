#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+10;
ll a[N],n,m;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans = 0;
	long long sum = 0;
	for (int i=1,p=1;i<=n;i++) {
		sum += 1ll * (i - p) * (a[i] - a[i-1]);
		while (sum > m) {
			sum -= (a[i] - a[p]);
			p++;
		}
		ans = max(ans, (i - p + 1));
	} 
	cout << ans;
	return 0;
} 
