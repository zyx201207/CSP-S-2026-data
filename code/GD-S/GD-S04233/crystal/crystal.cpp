#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],ans[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool q=0;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(m>=a[2]-a[1]){
			cout<<2;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	for(long long i=3;i<=n;i++){
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
			q=1;
		}
	}
	if(q==1){
		for(long long i=1;i<=n;i++){
			ans[i]=ans[i-1]+a[i];
		}
		long long mx=1;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if((j-i)*a[j]-ans[j-1]+ans[i-1]<=m){
					mx=max(j-i+1,mx);
				}
			}
		}
		cout<<mx;
	}
	else{
		long long sum=0,mx=0;
		for(long long i=1;i<=n-1;i++){
			if(sum<=m){
				mx=max(mx,i);
			}
			sum+=i*(a[2]-a[1]);
		}
		cout<<mx;
	}
	return 0;
}
