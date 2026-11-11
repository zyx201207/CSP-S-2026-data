#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010011],ans,sum;
long long op[1010011],mod=1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=mod;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		op[i]=op[i-1]+a[i];
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			long long k=(i-mid+1)*a[i]-(op[i]-op[mid-1]);
			if(k>m) l=mid+1;
			else r=mid-1,ans=max(ans,i-mid+1);
		}
	}cout<<ans;
	return 0;
}

