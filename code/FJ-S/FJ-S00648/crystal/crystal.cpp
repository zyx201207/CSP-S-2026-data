#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,r,mid,ans;
long long check(long long len){
	long long mip=a[len]*len-b[len],km;
	for(int i=2;i+len-1<=n;i++){
		km=a[i+len-1]*len-(b[i+len-1]-b[i-1]);
		mip=min(mip,km);
	}
	return mip;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)<=m){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
			ans=r;
		}
	}
	cout<<ans;
	return 0;
}
