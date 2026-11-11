#include <bits/stdc++.h>
using namespace std;
int n,m,b[6],c[6],ans[5],t;

int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	queue<int> p;#include <bits/stdc++.h>
using namespace std;
int n,m,b[6],c[6],ans[5],t;

int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	queue<int> p;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		
	}
	if(n<=5)
	{
		for(int i=1;i=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(b[j]==0)
				{
					b[j]++;
					p.push(b[j]);
				}
				else
				{
					int u=p.front();
					while(u!=b[j])
					{
						p.pop();
						u=p.front();
					}
					p.pop();
				}
			}
			while(!p.empty())
			{
				int u=p.front();
				p.pop();
				ans[u]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		
	}
	if(n<=5)
	{
		for(int i=1;i=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(b[j]==0)
				{
					b[j]++;
					p.push(b[j]);
				}
				else
				{
					int u=p.front();
					while(u!=b[j])
					{
						p.pop();
						u=p.front();
					}
					p.pop();
				}
			}
			while(!p.empty())
			{
				int u=p.front();
				p.pop();
				ans[u]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}