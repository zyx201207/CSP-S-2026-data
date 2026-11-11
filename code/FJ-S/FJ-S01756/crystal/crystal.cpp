#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],ans,s[500050],sum[500050];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		sum[i]=(i-1)*a[i]-s[i-1];
	}
	for(int i=1;i<=n;++i){
		if(sum[i]<=m) ans=max(i*1ll,ans);
		else{
			int l=1,r=i,nns=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if( (sum[i]- (mid*a[i]-s[mid]))<=m){
					nns=mid;
					r=mid-1;
				}
				else
					l=mid+1;
			}
			ans=max(ans,(long long)(i-nns));	
		}
	}
	cout<<ans;
	return 0;
}