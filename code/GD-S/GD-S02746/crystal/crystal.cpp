#include<bits/stdc++.h>
#define long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int y=0;
	for(int i=n-1;i>1;i--){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])y=1;
	}
	if(y==0){
		if(a[n-1]-a[n-2]==0)cout<<n;
		else{
			long long x=m;
			long long sum=1;
		 for(int j=n-2;j>=0;j--){
		 	if(x>=a[n-1]-a[j])sum++,x-=(a[n-1]-a[j]);
		 	else break;
		 }	
		 cout<<sum;
		}
		return 0;
	}
	long long maxsum=0;
	for(int i=n-1;i>=0;i--){
		 long long x=m;
		 long long sum=1;
		 for(int j=i-1;j>=0;j--){
		 	if(x>=a[i]-a[j])sum++,x-=(a[i]-a[j]);
		 	else break; 
		 }
		 if(sum>maxsum)maxsum=sum;
	}
	cout<<maxsum;
	return 0;
} 

