#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+66;
int n,m,a[N],sum[N],ans,tot;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	int l=1;
	for(int r=1; r<=n; r++) {
		if(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m) ans=max(ans,r-l+1);
		else {
			l++;
			tot=0;
		}
	}
	cout<<ans;
	return 0;
}

