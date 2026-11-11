#include<bits/stdc++.h>
using namespace std;
const int N=2893435;
int a[N],ans[N];
bool st[N];
queue<int> q;
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
	int x=n;
	int o=1;
	
	while(x--)
	{	
		while(!q.empty())
		{
			st[q.front()]=0;
			q.pop();
		}
		for(int i=o;i<=n;i++)
		{
			if(!st[a[i]])
			{
				q.push(a[i]);	
				st[a[i]]=1;
			}
			else
			{
				while(q.front()!=a[i])
				{
					st[q.front()]=0;
					q.pop();
				}
				q.pop();
				q.push(a[i]);
			}
			
		}
		queue<int> z;
		while(!q.empty())
		{
			z.push(q.front());
			ans[q.front()]++;
			q.pop();
		}
		while(!z.empty())
		{
			q.push(z.front());
			z.pop();
		}
		o++;
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
