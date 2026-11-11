#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,l,r,a[N],mid,ans,cnt,maxx,minn;
long long he(long long x){
	long long sum=0;
	for(long long i=1;i<=n;i++){
		if(x>a[i]) sum+=(x-a[i]);
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&a[1]);
	maxx=a[1];
	minn=a[1];
	for(long long i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	l=minn;
	r=maxx;
	while(l<=r){
		mid=l+r>>1;
		if(he(mid)<=m) l=mid+1;
		else r=mid-1;
	}
	for(long long i=1;i<=n;i++)
		if(a[i]<=r) ans++;
	printf("%lld\n",ans);
	return 0;
}
