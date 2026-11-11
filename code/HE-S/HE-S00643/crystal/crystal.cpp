#include <bits/stdc++.h>
using namespace std;

#define int long long
#define il inline
#define N 500300
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define eb emplace_back

const int inf=1e18;

il int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
} 

int n,m,sum[N];
int a[N];

il int check(int x){
	FOR(i,1,n){
		if(i>=x){
			int p=sum[i]-sum[i-x];
			int k=x*a[i]-p;
			if(m>=k) return 1;
		}
	}
	return 0;
}



signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	n=read(),m=read();
	int mx=-inf,mn=inf;
	FOR(i,1,n){
		a[i]=read();
		int x=a[i];
		mx=max(mx,x);
		mn=min(mn,x);
	}
	sort(a+1,a+n+1);
	FOR(i,1,n){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
} 
