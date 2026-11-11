#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool ok=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)
		ok=false;
	}
	if(ok){
		int sum=0,sum1=0;
		for(int i=0;1;i++){
			sum+=i;
			if(sum>m){
				cout<<sum1;
				break;
			}
			sum1+=i;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]-a[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(sum[j]-sum[i-1]<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
