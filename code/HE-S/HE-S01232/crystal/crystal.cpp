#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
const long long M=1e12+5;
long long n,m;
long long a[N];
long long sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=M;
	} 
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	long long ans=1;
	
	for(long long i=2;i<=n;i++){
		long long cost=( (i-1)*a[i] )-sum[i-1];
		if( cost <=m){
			ans=max(ans,i);
		} else {
			long long j=1;
			while(j<=i &&cost>m){
				cost=cost-(a[i]-a[j]);
				j++;
				
			}
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}
