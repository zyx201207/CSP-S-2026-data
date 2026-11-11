#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,m,a[N],s[N];
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=1;
	for (ll i=2;i<=n;i++) {
		int l=0,r=i-1,t=i;
		while (l<r) {
			int mid=(l+r)/2;
			if (a[i]*(i-mid-1)-s[i-1]+s[mid]<=m) {
				t=mid;
				r=mid;
			}else l=mid+1;
		}
		ans=max(ans,i-t);
	}
	cout << ans <<"\n";
	return 0;
}
