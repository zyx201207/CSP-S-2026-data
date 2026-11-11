#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
inline int calc(int p) {
	int l=1,r=p,res=1;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (1ll*mid*a[p]-(s[p]-s[p-mid])<=m) res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m; int ans=1;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++) ans=max(ans,calc(i));
	cout<<ans<<"\n";
	return 0;
}