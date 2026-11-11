#include <bits/stdc++.h>
using namespace std;
int id[500005],id1[500005],vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int a[500005];
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<int> q;
	for (int i=1;i<=n;i++)
	{
		memset(id,0,sizeof(id));
		int ans=0;
		int h=0;
		for (int j=i;j<=n;j++)
		{
			if (id[a[j]]>0)
			{
				for (int k=1;k<=j-h-id[a[j]] && !q.empty();k++)
				{
					id[q.top()]=0;
					h++;
					q.pop();
				}
				id[a[j]]=j-h;
			}
			q.push(a[j]);
			if (id[a[j]]==0)
			{
				id[a[j]]=j-h;
			}
		}
		memset(vis,1,sizeof(vis));
		while (!q.empty())
		{
			if (vis[q.top()]) 
			{
				id1[q.top()]++;
				vis[q.top()]=0;
			}
			q.pop();
		}	
	}
	for (int i=1;i<=m;i++)
	{
		cout<<id1[i]<<" ";
	}
	return 0;
}
