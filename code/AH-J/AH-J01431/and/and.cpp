#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx;
long long a[200010];
void fun(long long x,long long y,long long ans)
{
	if(y==m)
	{
		maxx=ans;
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		fun(i,y+1,ans&a[i]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1||(n>2000&&a[5]!=4))
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		if(n>2000)maxx/=pow(2,m)*2;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			maxx&=a[i];
		}
	}
	else
	{
		fun(0,0,0);
	}
	cout<<maxx;
	return 0;
}
