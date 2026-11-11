#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,cnt[212345]= {0},num[212345]= {0};
void dfs(int a,int b)
{
	if(a>m)
	{
		int x=cnt[1];
		for(int i=1; i<a; i++)
		{
			x&=cnt[i];
		}
		ans=max(ans,x);
		return ;
	}
	for(int i=b+1; i<=n; i++)
	{
		cnt[a]=num[i];
		dfs(a+1,i);
		cnt[a]=0;
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>num[i];
	}
	if(m==1)
	{
		for(int i=1; i<=n; i++) ans=max(ans,num[i]);
	}
	else if(m==2)
	{
		for(int i=1; i<n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				ans=max(ans,num[i]&num[j]);
			}
		}
	}
	else if(m==n)
	{
		for(int i=1; i<=n; i++) ans&=num[i];
	}
	else if(n<=20)
	{
		dfs(1,0);
	}
	else
	{
		ans=1e9;
		for(int i=1; i<=n; i++) ans=min(ans,num[i]);
	}
	cout<<ans;
	return 0;
}
