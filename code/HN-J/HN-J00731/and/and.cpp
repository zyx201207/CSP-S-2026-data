#include<bits/stdc++.h>
using namespace std;
long long n,s,k,m,a[200010];
bool b[200010];
void dfs(int x,int y,long long z)
{
	if(y==m)
	{
		m=max(m,z);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			dfs(i,y+1,z&a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==n)
	{
		s=a[1];
		for(int i=2;i<=n;i++)
		{
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		dfs(i,0,a[i]);
	}
	cout<<m;
	return 0;
}

