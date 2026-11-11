#include<bits/stdc++.h>
using namespace std;

#define N 500005
long long n,m,a[N],sum[N],j,l,r,mid,ans=1,temp;

long long bf(long long x){
	l=0,r=x;
	while(l+1<r){
		mid=l+(r-l)/2;
		temp=a[x]*(x-mid+1)-sum[x]+sum[mid-1];
		if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]<=m) r=mid;
		else l=mid;
	}
	return r;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		j=bf(i);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
