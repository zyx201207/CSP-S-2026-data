#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=5e5+10;
inline int readInt(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline ll readll(){
	char c=getchar();ll x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1ll;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10ll+c-'0';c=getchar();}
	return x*f;
}
int n,lt=1,ans;
ll m,k,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
	n=readInt(),m=readll();
	for(int i=1;i<=n;i++) a[i]=readll();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(a[i]*(i-lt+1)-(sum[i]-sum[lt-1])>m){lt++;}
		ans=max(ans,i-lt+1);
	}
	printf("%lld",ans);
//	freopen("crystal4.ans","r",stdin);
//	m=readll();
//	printf("%lld",m);
	return 0;
}

