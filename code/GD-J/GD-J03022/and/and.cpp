#include<bits/stdc++.h>
using namespace std;
bool v[200005];
long long a[200005],n,m,maxx,e,ma=-1;
void dfs(int x,long long k,int d)
{
	if(d==m) 
	{
		ma=max(ma,k);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			dfs(i,k&a[i],d+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	e=a[1];
	maxx=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]; 
		maxx=max(maxx,a[i]);
		e=e&a[i];
	}
	if(m==n)
	{
		cout<<e;
		return 0;
	}
	if(m==n-1)
	{ 
		maxx=0;
		e=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				else e=e&a[j]; 
			}
			maxx=max(e,maxx);
		}
		cout<<maxx;
		return 0;
	}
	if(m==1||n>=200000)
	{
		cout<<maxx;
		return 0;
	} 
	for(int i=1;i<=n;i++)
	{
		v[i]=1;
		dfs(i,a[i],1);
		v[i]=0;
	}
	cout<<ma;
}
