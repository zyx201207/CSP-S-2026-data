#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N+1];
int n,m;
int ans[N+1];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int> card;
		bool vis[N+1]={0};
		card.push(a[i]);
		vis[a[i]]=1;
		for(int j=i;j<=n;j++)
		{
			if(card.empty())
				continue;
			if(vis[a[j]]==1)
			{
				while(card.top()!=a[j])
				{
					vis[card.top()]=0;
					card.pop();
				}
			}
			else
			{
				vis[a[j]]=1;
				card.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i]==1)
				ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
