#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,ans;
LL a[200100];
int v[200100];
void dfs(LL k,LL s,LL p)
{
	if(k==m)
	{
		ans=max(ans,s);
		return;
	}
	if(p==n) return;
	if(!v[p])
	{
		v[p]=1;
		dfs(k+1,s&a[p],p+1);
		v[p]=0;
	}
	dfs(k,s,p+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		v[i]=1;
		dfs(1,a[i],1);
		v[i]=0;	
	}
	printf("%lld",ans);
	return 0; 
}
