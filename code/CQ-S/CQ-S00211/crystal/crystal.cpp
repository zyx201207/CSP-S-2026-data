#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n;
long long m;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long j=1,ans=0;
	for(long long i=1;i<=n;i++){
		long long num1=sum[i]-sum[j-1];
		long long num2=a[i]*1LL*(i-j+1);
		while(num2-num1>m){
			j++;
			num1=sum[i]-sum[j-1];
			num2=a[i]*1LL*(i-j+1);
		}	
		ans=max(ans,(i-j+1));
	}
	cout<<ans;
	return 0;
}
