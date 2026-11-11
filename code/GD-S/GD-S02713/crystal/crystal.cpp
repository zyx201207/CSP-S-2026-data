#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN];
__int128 b[MAXN];
long long n,m;
bool check(long long x){
	__int128 lll=m;
	for(long long i=x;i<=n;i++){
		__int128 k=x*a[i];
		if(lll>=k-(b[x]-b[i-x])) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	long long l=1,r=n;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}
	int f=1;
	int gc=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=gc) f=0;
	}
	if(f){
		int u=m,an=0;
		for(int i=n;i>=1;i--){
			u-=(a[n]-a[i]);
			if(u>=0) an++;
			else break;
		}
		ans=an;
	}
	printf("%lld",ans);
	return 0;
} 
