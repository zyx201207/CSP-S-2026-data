#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[200005];
int maxx=INT_MIN;
int maxx2=INT_MIN;
int maxx3=INT_MIN;
void dfs(int step,int ans,int sum)
{
	int p=ans;
	if(step>n||sum>m)
	{
		if(sum==m)
		{
			maxx=max(ans,maxx);
		}
		return ;
	}
	dfs(step+1,(ans&a[step]),sum+1);
	ans=p;
	dfs(step+1,ans,sum);
	ans=p;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx2=max(maxx2,a[i]);
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		dfs(1,a[i],0);
		cout<<maxx;
	}
	else
	{
		if(m==1)
		{
			cout<<maxx2;
		}
		else if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					maxx3=max(maxx3,(a[i]&a[j]));
				}
			}
		}
	}
	return 0;
}

