#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],maxv=-1,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==3)l=abs(a[2]-a[1]);
		if(abs(a[i]-a[i-1])!=l&&i>=3)f=false;
	}
	if(f){
		long long k=(1+n)/2+1,x=0,ans=0;
		for(long long i=1;i<k;i++){
			if(abs(a[k]-a[k-i])+x<=m){
				ans++,x+=(a[k]-a[k-i]);
			}else{
				cout<<ans+1;
				return 0;
			}
			if(abs(a[k]-a[k+i])+x<=m&&k+i<=n){
				ans++,x+=(a[k]-a[k-i]);
			}else{
				cout<<ans+1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long p=m,sum=0;
		for(long long j=1;j<=n;j++)b[j]=abs(a[i]-a[j]);
		sort(b+1,b+n+1);
		while(p>=0){
			sum++,p-=b[sum];
			if(sum>n){
				cout<<n;
				return 0;
			}
		}
		sum--;
		maxv=max(maxv,sum);
	} 
	cout<<maxv;
	return 0;
} 
