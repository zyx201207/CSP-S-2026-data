#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[300005];
int c[500005];
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
		stack<int>q;
		for(int j=1;j<=m;j++)
		{
			vis[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				while(1)
				{
					int b=q.top();
					q.pop();
					if(b==a[j])
					{
						break;
					}
					else
					{
						vis[b]=0;
					}
				}
			}
			q.push(a[j]);
			vis[a[j]]=1;
		}
		while(!q.empty())
		{
			int b=q.top();
			q.pop();
			c[b]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
 } 
