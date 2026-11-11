#include<bits/stdc++.h>
	
using namespace std;

long long n,m,a[200010],b[200010],c[200010],maxx=-9e18;
vector<long long> q;
bool cmp(long long a,long long b)
{
	return a>b;
}
void dfs(long long u)
{
	if(u==n+1)
	{
		long long C=a[q[0]];
		bool f=0;
		if(q.size()==m)
		{
			for(long long x:q)
			{
				if(f)
				{
					C&=a[x];
				}
				else 
				{
					C&=a[x];
				}
			}
		}
		maxx=max(maxx,C);
		return ;
	}
	q.push_back(u);
	dfs(u+1);
	q.pop_back();
	dfs(u+1);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)	
	{
		long long C=0;
		for(long long i=1;i<=n;i++)
		{
			C=max(C,a[i]);
		}
		cout<<C;
		return 0;
	}
	else if(m==n)
	{
		long long C=a[1];
		for(long long i=2;i<=n;i++)
		{
			C&=a[i];
		}
		cout<<C;
		return 0;
	} 
	else if(m==2)	
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(n<=20)
	{
		dfs(n);
		cout<<maxx;
		return 0;
	}
	else 
	{
		sort(a+1,a+n+1,cmp);
		long long C=a[1];
		for(long long i=2;i<=m;i++)
		{
			C&=a[i];
		}
		cout<<C;
		return 0;
	}
	return 0;
}
