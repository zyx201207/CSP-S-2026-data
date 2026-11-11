#include<bits/stdc++.h>
using namespace std;
long long s[3000000],s2[3000000],s1[3000000],n,m,sum=0;
void dfs(long long k,long long y)
{
	if(k==m)
	{
		long long x=0;
		for(int i=1;i<=m;i++)
		{
			if(i==1)
			{
				x=s1[i];
			}
			else
			{
				x=(x&s1[i]);
			}
		}
		if(x>sum)
		{
			sum=x;
		}
		return;
	}
	for(int i=y+1;i<=n;i++)
	{
		if(!s2[i])
		{
			s2[i]=1;
			y=i;
			s1[k+1]=s[i];
			dfs(k+1,y);
			s2[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	dfs(0,0);
	cout<<sum;
	return 0;
}
