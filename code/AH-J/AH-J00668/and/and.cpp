#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],maxn,m;
void dfs(long long x,long long k,int p)
{
	if(p==m){
		maxn=max(maxn,k);
		return ;
	}
	if(x==n+1)return ;
	if(p==0)dfs(x+1,a[x],p+1);
	else dfs(x+1,k&a[x],p+1);
	dfs(x+1,k,p);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		printf("%lld",maxn);
		return 0;
	}
	maxn=0;
	dfs(1,0,0);
	printf("%lld",maxn);
	return 0;
} 
