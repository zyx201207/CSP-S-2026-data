#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],c[500050];
bool check(long long x){
	long long sum=0,ans=4e18;
	for(long long i=1;i<=n;i++){
		sum+=(min(x-1,i-1))*c[i];
		if(i>x){
			sum=sum-(a[i-1]-a[i-x]);
			ans=min(ans,sum);
			
//			if(x==315276){
//				cout<<sum<<endl;
//			}
			
		}
		if(i==x){
			ans=min(ans,sum);
		}
	}
	
	
	
	if(ans<=m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
//	for(long long i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	
	for(long long i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	long long l=1,r=n;
	while(l<r){
		long long mid=l+(r-l+1)/2;
//		cout<<mid<<endl;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
} 
