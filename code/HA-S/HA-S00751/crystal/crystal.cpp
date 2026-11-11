#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
long long sum[500005];
bool f(int x){
	long long k=0;
	for(int i=x;i<=n;i++){
		k=sum[i]-sum[i-x];
		if(k+m>=a[i]*x)
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=l+r>>1;
		if(f(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
