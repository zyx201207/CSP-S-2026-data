#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int>q;
		for(int j=i;j<=n;j++)
		{
			stack<int>p;
			int x;
			while(!q.empty())
			{
				x=q.top();
				q.pop();
				if(x==a[j])
					break;
				else
					p.push(x);
			}
			if(q.empty()&&x!=a[j])
			{
				while(!p.empty())
				{
					int x=p.top();
					p.pop();
					q.push(x); 	
				}
			}
			q.push(a[j]);
		}
		while(!q.empty())
		{
			int x=q.top();
			q.pop();
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
