#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
const int N=500085;
int n,m,a[N],sum[N],cnt;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid,minx;
	while(l<r) {
		mid=l+(r-l)/2,minx=1e18;
		for(int i=1;i<=n-mid+1;++i) {
			minx=min(minx,a[i+mid-1]*mid-sum[i+mid-1]+sum[i-1]);
		}
		if(minx>m) {
			r=mid;
		} else if(minx==m) {
			cout<<mid<<'\n';
			return 0;
		} else {
			l=mid+1;
		}
	}
	cout<<mid<<'\n';
 	return 0;
}
