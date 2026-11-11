//GZ-S00074 ³ÂèªÄÏ 
#include<bits/stdc++.h>
using namespace std;
long long a[2000010],sum[2000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]); 
	}
	long long ans=1;
	for(long long i=2;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(sum[i]-sum[mid-1]-(i-mid+1)*(a[mid]-a[l])>m){
				l=mid+1;
			}
			else{
				r=mid;
			}
			
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
