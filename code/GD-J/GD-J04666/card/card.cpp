#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int cnt[500010];
int vis[500010];
stack<int> b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				b.push(a[i]);
				vis[a[i]]=1;//ok	
			}
			else
			{
				while(!b.empty()&&b.top()!=a[i])
				{
					vis[b.top()]=0;
					b.pop();
				}
			}	
			
		}
		while(!b.empty())
			{
				vis[b.top()]=0;
				cnt[b.top()]++;
				b.pop();
			}
	}	
	for(int i=1;i<m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	cout<<cnt[m]+1;
	return 0;
}
