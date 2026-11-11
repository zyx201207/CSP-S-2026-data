#include <bits/stdc++.h>
using namespace std;
const long long N=500005,INF=1e13+5;
long long a[N],c[N],sum[N],n,m,maxn,minn=INF;
//c[i]:第i小的与第i-1小之差 
bool check(int k){
	long long res=0,t=lower_bound(a+1,a+1+n,n-k+1)-a;
	for(int i=1;i<=n-k+1;i++){
		res=(a[i+k-1]*k-sum[i+k-1]+sum[i-1]);
		//printf("%lld ~ %lld : %lld\n",i,i+k-1,a[i+k-1]*k);
		
		if(res<=m)return 1;
	}
	return 0; 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//sum[i]=sum[i-1]+a[i];
		maxn=max(maxn,a[i]); 
		minn=min(minn,a[i]);
	}
	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<" "; 
	}
	long long l=0,r=n,ans=0,cnt=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		//cout<<mid<<" ";
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
