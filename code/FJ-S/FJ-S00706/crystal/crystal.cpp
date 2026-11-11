#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],h[500005],hh[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		h[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		hh[i]=hh[i-1]+h[i]*i;
	}
	long long l=1,r=n,ans=0,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(hh[mid]<=m){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans+1;
	return 0;
}
