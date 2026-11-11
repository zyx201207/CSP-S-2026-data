#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,sum[500005];
long long ch(long long l,long long r,long long m){//查找在sum[i]中最接近m的数 但<=m 
	if((l+r)/2+1>=r){
		if(sum[r]>m)return r-1;
		else return r;
	}
	int mid=(l+r)/2+1;
	if(sum[mid]>m){
		ch(l,mid,m);
	}else if(sum[mid]==m){
		return mid;
	}else{
		long long minn=m-a[mid];
		long long zhi=ch(mid,r,m); 
		if(sum[zhi]<m && minn>m-sum[zhi]){
			return zhi;
		}else{
			return mid;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
	}
	sort(a+1,a+n+1);
	printf("%lld",ch(1,n,m));
}
