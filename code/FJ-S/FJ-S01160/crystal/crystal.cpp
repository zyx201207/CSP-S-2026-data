#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],sum[1000010];
bool check(long long x){
	long long minn=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n-x+1;i++)minn=min(minn,x*a[i+x-1]-sum[i+x-1]+sum[i-1]); 
	return minn<=m;
}
long long f(){
	long long l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	cout<<f();
	return 0;
}
