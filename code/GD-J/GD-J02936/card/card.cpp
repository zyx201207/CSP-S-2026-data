#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long ans[300005];
bool vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> cards;
		for(int k=i;k<=n;k++)
		{
			if(vis[a[k]]==1)
			{
				while(cards.size())
				{
					int t=cards.top();
					cards.pop();
					vis[t]=0;
					if(t==a[k])
					{
						break;
					}
				}
			}
			cards.push(a[k]);
			vis[a[k]]=1;
		}
		while(cards.size())
		{
			int t=cards.top();
			cards.pop();
			ans[t]++;
		}
		while(cards.size())
		{
			cards.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
