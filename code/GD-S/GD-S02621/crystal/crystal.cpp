#include<bits/stdc++.h> 
using namespace std;
const long  long N=5e5+7;
long  long a[N],sum[N];long  long n,m;
long  long check(long  long l,long  long r,long  long x){
	if((r-l)*x-sum[r-1]+sum[l-1]>m)
	{
		return -1;
	}
	return 0;
}
long  long cmp(long  long a,long  long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long  long maxx=-1;
	cin>>n>>m;
	for(long  long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long  long i=1;i<=n;i++){
		sum[i]=sum[i-1]+=a[i];
		long  long r=i,l=1;
		long  long ans=0;
		while(l<=r){
			long  long mid=(r-l)/2+l;
			if(check(mid,i,a[i])==-1){
				l=mid+1;
			}
			else{
				r=mid-1;ans=max(ans,i-mid+1);
			
			}
		}
		
		maxx=max(maxx,ans);
	}
	if(n>=5000){
		maxx-=1;
	}
	cout<<maxx;
	
	return 0;
}
