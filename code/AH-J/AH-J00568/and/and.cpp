#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],s;
bool b[200001];
int mn=2e9,x;
bool emp(const int &a,const int &b)
{
	return a>b;
}
void dfs(int u,int ss)
{
	if(u==0)
	{
		s=max(s,ss);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			dfs(u-1,ss&a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,emp);
	if(m==1)
	{
		printf("%d",a[1]);
		return 0;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		printf("%d",ans);
		return 0;
	}
	else if(m==2)
	{
		int mn=-2e9;
		for(int i=1;i<n;i++)
		{
			int xx=a[i]&a[i+1];
			mn=max(mn,xx);
		}
		printf("%d",mn);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		dfs(m-1,a[i]);
		b[i]=0;
	}
	cout<<s;
	return 0;
}

