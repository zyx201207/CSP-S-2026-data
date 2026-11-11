#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],vis[300005],ans[300005];
deque<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			q.push_back(a[j]);
			if(vis[a[j]]==0)
			{
				vis[a[j]]=j;
			}
			else
			{
				for(int k=vis[a[j]];k<=j;k++)
				{
					q.pop_back(); 
				} 
				q.push_back(a[j]); 
			}
		} 
		while(q.size()!=0)
		{
			int p=q.front();
			ans[p]++;
			q.pop_front();
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" "; 
	} 
}
