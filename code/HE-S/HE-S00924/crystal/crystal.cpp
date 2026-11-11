#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+3;

long long n,m,a[maxn],sum[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}
		r++;
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
