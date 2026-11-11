#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],p[200010],s1,ms=-1;
bool v[200010];
void dfs(long long s)
{
	for(long long i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			p[s]=i;
			v[i]=1;
			if(s==m)
			{
				s1=a[p[1]];
				for(long long i=1;i<=m;i++)
				{
					s1&=a[p[i]];
				}
				if(s1>ms)
				{
					ms=s1;
				}
			}
			else
			{
				dfs(s+1);
			}
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	s1=a[1];
	dfs(1);
	cout<<ms;
	return 0;
}
