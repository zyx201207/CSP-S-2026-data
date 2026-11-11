#include <bits/stdc++.h>
using namespace std;
const int M=1e6;
long long a[M];
long long int ans;
long long int n,m,maxn=-1;
bool vis[M];
void dfs(long long int x) {
	if(x==m) {
		maxn=max(ans,maxn);
		return ;
	}
	for(int i=x;i<=n;i++) {
		if(!vis[i+x]&&x+i<=n) {
			vis[i+x]=1;
			ans&=a[i+x];
			dfs(i+x);
			vis[i+x]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	long long int mann=-1;
	for(long long int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		mann=max(mann,a[i]);
	}
	if(m==1) {
		printf("%lld",mann);
		return 0;
	}
	if(n==m) {
		long long sum=a[1];
		for(long long int i=2;i<=n;i++) {
			sum&=a[i];
		}
		printf("%lld",sum);
		return 0;
	}
	for(int i=1;i<=n;i++) {
		vis[i]=1;
		ans=a[i];
		dfs(i);
		vis[i]=0;
	}
	printf("%lld",ans);
	return 0;
}
