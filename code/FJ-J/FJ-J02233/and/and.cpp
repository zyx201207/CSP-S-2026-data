#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],max1=INT_MIN,zj=INT_MIN;
bool f[200005]={false};
void dfs(long long x,long long y,long long sum)
{
	if(x==m)
	{
		zj=max(zj,sum);
		return ;
	}
	for(int i=y;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=true;
			if(x==1) dfs(x++,i+1,a[i]);
			else dfs(x++,i+1,(sum&a[i]));
			f[i]=false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		max1=max(max1,a[i]);
	}
	if(m==1)
	{
		cout<<max1;
		return 0;
	}
	dfs(1,1,0);
	cout<<zj;
	return 0;
}  
