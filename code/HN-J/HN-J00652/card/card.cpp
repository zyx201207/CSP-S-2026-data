#include<bits/stdc++.h>
using namespace std;
stack<long long int> s;
long long int n,m,a[500010],vis[300010],ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(long long int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				s.push(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(long long int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
