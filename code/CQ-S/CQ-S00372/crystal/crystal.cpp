#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005]={};
int sum[500005]={};
int n=0,limit_=0;
bool check(int k,int now){
	return (k*a[now]-sum[now-1]+sum[now-1-k])<=limit_;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&limit_);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int max_=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i-1;
		while(l<r){
			int mid=l+r+1>>1;
			if(check(mid,i)) l=mid;
			else r=mid-1;
		}
		max_=max(max_,l+1);
	}
	printf("%lld",max_);
}
