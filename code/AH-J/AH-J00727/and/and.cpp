#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL N=2e5+10,inf=(1LL<<30)-1;
LL n,m,dp[N],maxn,maxa,suma=inf,suml[N],sumr[N],a[N],ans[N],num[5];
bool ok=1,f=1;
void dfs(LL cur,LL sum,LL pre){
	if(sum<=maxn)	return;
	if(cur>m){maxn=sum;return;}
	for(LL i=pre+1;i<=n;++i)	dfs(cur+1,sum&a[i],i);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ans[1]=0;
	scanf("%lld%lld",&n,&m);
	suml[0]=sumr[n+1]=inf;
	for(LL i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		maxa=max(maxa,a[i]);
		suma&=a[i];suml[i]=suml[i-1]&a[i];
		LL x=a[i]+1;
		if((x&-x)!=x)	ok=0;
		if(a[i]!=i-1)	f=0;
	}
	for(LL i=n;i>=1;--i)	sumr[i]=sumr[i+1]&a[i];
	if(n>=20){
		dfs(1,inf,0);
		printf("%lld",maxn);
	}
	else if(m==1)	printf("%lld",maxa);
	else if(m==n)	printf("%lld",suma);
	else if(m==2){
		for(LL i=1;i<=n;++i)
		for(LL j=i+1;j<=n;++j)	maxa=max(maxa,a[i]&a[j]);
		printf("%lld",maxa);
	}
	else if(m==n-1&&n!=1){
		for(LL i=1;i<=n;++i)	maxa=max(maxa,suml[i-1]&sumr[i+1]);
		printf("%lld",maxa);
	}
	else if(ok&&n!=1){
		sort(a+1,a+n+1,greater<LL>() );
		suma=inf;
		for(LL i=1;i<=m;++i)	suma&=a[i];
		printf("%lld",suma);
	}
	else if(f&&(n&-n)==n)	printf("%lld",ans[n]);
	else if(maxa<4){
		for(LL i=1;i<=n;++i)	num[a[i]]++;
		if(num[3]>=m)	puts("3");
		else if(num[3]+num[2]>=m)	puts("2");
		else if(num[3]+num[1]>=m)	puts("1");
		else puts("0");
	}
	return 0;
}
