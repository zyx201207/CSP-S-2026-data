#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N],n,m;
bool check(int x){
	for(int i=1;i<=n-x+1;i++)
		if(x*a[i+x-1]-sum[i+x-1]+sum[i-1]<=m) return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
