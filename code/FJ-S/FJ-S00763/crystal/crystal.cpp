#include<bits/stdc++.h>
using namespace std;

long long n,m;
const int N=5e5+5;
long long a[N];
long long pre[N];
long long ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	if(n<=5000){
		sort(a+1,a+n+1);
	
		for(int i=2;i<=n;i++){
			pre[i]=a[i]-a[i-1];
		}
		
		long long sum=0;
		long long i=1,j=2;
		while(i<j && j<=n && i<=n){
			sum+=pre[j]*(j-i);
			if(sum>m){
				for(int k=i;k<=j;k++) sum-=pre[k];
				i++;
			} else j++;
			ans=max(ans,j-i);
		}
		cout<<ans;
	} else {
		sort(a+1,a+n+1);
		long long l=1,r=n;
		while(l<=r){
			long long mid=(l+r)/2;
			if((a[1]+a[mid])*mid/2>m) r=mid;
			else if((a[1]+a[mid])*mid/2<m){
				ans=max(ans,mid);
				l=mid;
			} else{
				ans=mid;
				break;
			}
		}
		cout<<ans+1;
	}
	return 0;
}

