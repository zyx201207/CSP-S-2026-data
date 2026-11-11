#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],dif[N],sum[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	//scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		//scanf("%lld",&a[i]);
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		dif[i]=a[i+1]-a[i];
		sum[i+1]=sum[i]+dif[i];
	}
	/*for(int i=1;i<=n;++i){
		printf("%lld %lld\n",dif[i],sum[i]);
	}*/
	int i=1,j=1;
	int need=0;
	while(j<=n){
		need+=dif[j-1]*(j-i);
		if(need>m){
			ans=max(ans,j-i);
			while(need>m){
				need-=sum[j]-sum[i];
				++i;
			}
		}
		++j;
		//printf("%lld\n",need);
	}
	ans=max(ans,j-i+1);
	printf("%lld",ans);
	return 0;
}
