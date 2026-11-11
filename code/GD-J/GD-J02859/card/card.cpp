#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=1;j<=n;j++)
	{
		bool vis[500010]={0};
		queue<int> q;
		for(int i=j;i<=n;i++)
		{
			if(vis[a[i]]==0)q.push(a[i]),vis[a[i]]=1;
			else 
			{
				queue<int> p;
				while(!q.empty())
				{
					if(q.front()==a[i])while(!q.empty())q.pop();
					else p.push(q.front()),q.pop();
				}
				memset(vis,0,sizeof(vis));
				while(!p.empty())
				{
					vis[p.front()]=1;
					q.push(p.front()),p.pop();
				}
				q.push(a[i]);
				vis[a[i]]=1;
			}
		}
		while(!q.empty())
		{
			ans[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
