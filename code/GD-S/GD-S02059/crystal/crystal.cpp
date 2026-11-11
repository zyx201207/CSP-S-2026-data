#include<bits/stdc++.h>
#define gc getchar
using namespace std;
const int N=5e5+10;
const long long inf=1e18;
inline void re(long long &s){
	s=0;
	char a=gc();
	short f=1;
	while(!isdigit(a)){
		if(a=='-') f=-1;
		a=gc();
	}
	while(isdigit(a)){
		s=(s<<3)+(s<<1)+(a-'0');
		a=gc();
	}
	s*=f;
}
long long i,j,n,m,a[N],l,r,dif[N],mid;
int same[N];
unsigned long long sum[N],tmp,ans;
inline long long check(int u){
	unsigned long long an=inf;
	for(int i=u;i<=n;i++){
		tmp=(u-1)*a[i]-(sum[i-1]-sum[i-u]);
		an=min(an,tmp);
	}
	return an;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	re(n);
	re(m);
	for(int i=1;i<=n;i++){
		re(a[i]);
	} 
	sort(a+1,a+1+n);
	l=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		dif[i]=a[i]-a[i-1];
		if(dif[i]==0){
			same[i]=same[i-1]+1;
			l=max(l,1LL*same[i]);
		}
	}
	r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)<=m){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%llu",ans);
	return 0;
}

