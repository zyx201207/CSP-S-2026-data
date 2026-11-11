#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
unsigned long long sum[500005];
long long m,ans=1;
long long minn=1e18;
bool check(int mid,int i){
	if(mid*a[i]-(sum[i-1]-sum[i-mid-1])<=m)	return 1;
	return 0;
}
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		minn=min(minn,a[i]);
	}
	minn=abs(minn);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)	a[i]+=minn;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		long long k=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))	k=mid,l=mid+1;
			else	r=mid-1;
		}
		ans=max(ans,k);
	}
	cout<<ans+1;
	return 0;
}