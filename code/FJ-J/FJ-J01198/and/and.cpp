#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const ll MAXN=2e5+5,INF=262143;
ll n,m,ans,dp[MAXN],maxx,cnt;
bool f[MAXN],vis;
struct Node {
	ll a,er;
} num[MAXN];
ll query(ll n) {
	ll cnt=0;
	while(n) {
		cnt+=(n%2);
		n/=2;
	}
	return cnt;
}
bool cmp(Node a,Node b) {
	return a.er>b.er;
}
void dfs(ll x,ll now) {
	if(x==0) {
		ans=max(ans,now);
		return ;
	}
	for(ll i=1; i<=n; i++) {
		if(!f[i]) {
			f[i]=1;
			dfs(x-1,now&num[i].a);
			f[i]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(ll i=1; i<=n; i++) {
		num[i].a=read();
		num[i].er=query(num[i].a);
		if(query(num[i].a+1)!=1) {
			vis=1;
		}
	}
	for(ll i=1; i<=n; i++) {
		if(num[i].er>maxx) {
			maxx=num[i].er;
			cnt=num[i].a;
		}
	}
	if(n<=20) {
		dfs(m,INF);
		printf("%lld",ans);
		return 0;
	} else if(n==m) {
		for(ll i=1; i<=n; i++) {
			ans&=num[i].a;
		}
		printf("%lld",ans);
		return 0;
	} else if(m==1) {
		printf("%lld",cnt);
		return 0;
	} else if(m==2) {
		for(ll i=1; i<=n; i++) {
			for(ll j=1; j<=n; j++) {
				if(i!=j)
					ans=max(ans,num[i].a&num[j].a);
			}
		}
		printf("%lld",ans);
		return 0;
	} else if(!vis) {
		sort(num+1,num+n+1,cmp);
		ans=INF;
		for(ll i=1; i<=m; i++) {
			ans&=num[i].a;
		}
		printf("%lld",ans);
		return 0;
	}
	printf("0");
	return 0;
}
