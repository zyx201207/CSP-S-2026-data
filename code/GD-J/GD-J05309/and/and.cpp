#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],da=1,ma;
long long biao[200005];
void dfs(long long wei,long long ci,long long shu)
{
	shu=(shu & a[wei]);
	if(ci==0)
	{
		if(shu>ma)ma=shu;
		return ;
	}
	biao[wei]=1;
	if(m==n-1)
	{
		long long t=wei+2;
		if(t>n)t=n;
		for(int j=wei;j<=t;j++)if(biao[j]!=1)dfs(j,ci-1,shu);
	}
	else for(int j=wei;j<=n;j++)if(biao[j]!=1)dfs(j,ci-1,shu);
	biao[wei]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=30;i++)da=da*2;
    da--;
    sort(a+1,a+1+n);
    if(m==1)
    {
    	cout<<a[n];
    	return 0;
	}
	if(m==n)
	{
		da=a[1];
		for(int i=2;i<=n;i++)
		{
			da=(da & a[i]);
		}
		cout<<da;
		return 0;
	}
	if(n<=2000||m==n-1)
	{
		for(int i=n;i>=1;i--)
		{
			dfs(i,m-1,da);
		}
		cout<<ma;
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		da=(da & a[i]);
		m--;
		if(m==0)
		{
			cout<<da;
			return 0;
		}
	}
	
	return 0;
}
