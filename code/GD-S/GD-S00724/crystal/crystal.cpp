#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];
long long n,m;
bool check(int x){
	unsigned long long num=0,mi; 
	for(int i=1;i<x;i++){
		num+=a[x]-a[i];
	}
	mi=num;
	for(int i=x+1;i<=n;i++){
		num-=(a[i-1]-a[i-x]);
		if(num<=m-(a[i]-a[i-1])*x)return 1;
		num+=(a[i]-a[i-1])*x;
		if(mi>num)mi=num;
	}
	if(mi<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	long long mx=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=0,r=n,ans=-1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
