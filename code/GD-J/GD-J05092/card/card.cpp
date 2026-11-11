#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[200007];
stack<int>sta;
int ans[200007];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		bool vis[200007]={0};
		bool f[200007]={0};
		for (int j=i;j<=n;j++)
		{
			if (!vis[a[j]])
			{
				sta.push(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				while (sta.top()!=a[j])
				{
					sta.pop();
				}
			}
			
		}
		while (!sta.empty())
		{
			f[sta.top()]=1;
			sta.pop();
		}
		for (int i=1;i<=n;i++)
		{
			if (f[i])
			{
				ans[i]++;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (ans[i]>0)
		{
			cout<<ans[i]<<" ";
		}
	}
}
