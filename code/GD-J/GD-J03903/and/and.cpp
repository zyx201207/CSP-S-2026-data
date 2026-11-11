#include<bits/stdc++.h>
using namespace std;
long long m,n,maxx=INT_MIN;
long long a[200005];
void dfs(long long summ,long long ans,long long aaa)
{
	if(summ==m)
	{
		maxx=max(maxx,ans);
		return;
	}
	if(aaa==n)
	{
		return;
	}
	long long sss=(ans&a[aaa+1]);
	dfs(summ+1,sss,aaa+1);
	dfs(summ,ans,aaa+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(0,1,0);
	cout<<maxx; 
	return 0;
}
