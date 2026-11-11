#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m;
	for (int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for (int i=n;i>=2;--i){
		int l=1,r=i-1,mid;
		while (l<=r){
			mid=(l+r)>>1;
			int t=i-mid+1;
			if (t*a[i]-sum[i]+sum[mid-1]<=m){
				ans=max(ans,t);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
