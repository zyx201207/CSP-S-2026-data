#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
long long a[500005],n,m,s[500005],f[500005];
long long max(long long x,long long y){
	if(x>y)return x;
	return y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	f[1]=1;
	for(long long i=2;i<=n;i++){
		long long ans=-1;
		long long l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			long long len=i-mid+1;
			if(len*a[i]-(s[i]-s[mid-1])<=m){				
				r=mid-1;
			}else{
				l=mid+1;
			}
			ans=l;
		}
		/*for(long long j=i-1,k=2;j>=1;j--,k++){
			if(k*a[i]-(s[i]-s[j-1])<=m){
				ans=k;
			}
		}*/
		f[i]=max(f[i-1],i-ans+1);
	}
	cout<<f[n];
	return 0;
}
