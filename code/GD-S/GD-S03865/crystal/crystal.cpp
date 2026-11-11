#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010],ans=1,add;
int erfen(int f){
	long long l=1,r=f,mid,q;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[f]*(f-mid)-(sum[mid]-sum[f])<=m){
			q=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return q;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[i];
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) add++;
		else{
			ans=max(ans,add);
			long long q=erfen(i);
			add=i-q+1;
		}
	}
	ans=max(ans,add);
	cout<<ans;
	return 0;
}

