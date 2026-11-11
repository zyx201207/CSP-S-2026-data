#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500010],b[500010],c[500010],d[500010];
bool check(long long s){
	long long l=1,r=l+s-1;
	long long sum=0;
	for(;r<=n-1;l++,r++){
		sum=d[r]-d[l-1];
		sum-=((l-1)*(a[r+1]-a[l]));
		if(sum<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<n;i++){
		c[i]=i*b[i];
	}
	for(long long i=1;i<n;i++){
		d[i]=d[i-1]+c[i];
	}
	long long l=1,r=n-1;
	while(l<r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<l-1+1;
	return 0;
}
