#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l,r,mid;
	for(int i=1;i<=n;i++){
		l=1,r=i,mid=(l+r)>>1;
		while(l<=r){
			if(1ll*(i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid-1;
			else l=mid+1;
			mid=(l+r)>>1;
		}
		ans=max(ans,i-r);
//		cout<<r<<'\n';
	}
	cout<<ans;
	return 0;
} 
/*
5 5 
1 2 4 8 9
*/
