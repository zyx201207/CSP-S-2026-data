#include<bits/stdc++.h>
using namespace std;
long long n,i,a[500010],b[500010],t,w,ans,mid,m;
bool pd(long long x){
	long long l=1,r=x,sum=0;
	for(long long i=l;i<=r;i++) sum+=a[r]-a[i];
	if(sum<=m){
		return 1;
	} 
	while(r<n){
		sum-=a[r]-a[l];
		l++;r++;
		sum+=(x-1)*(a[r]-a[r-1]);
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	t=1;
	w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(pd(mid)) t=mid+1,ans=mid;
		else w=mid-1;
	} 
	cout<<ans;
	return 0;
}

