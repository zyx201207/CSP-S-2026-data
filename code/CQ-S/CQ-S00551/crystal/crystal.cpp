#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,ans,l,r,mid,a[500010],sum[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		l=1,r=i;
		while(l<=r){
			mid=(l+r)/2;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;	
	return 0;
} 
