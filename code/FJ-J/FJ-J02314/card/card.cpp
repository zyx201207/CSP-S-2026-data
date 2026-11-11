#include <bits/stdc++.h>
using namespace std;
const int N=5e5+12;
int n,a[N],m,ans[N],vis[N];
stack <int> s;
queue <int> q;
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
		for(int t=0;t<=m;t++)vis[t]=0;
		for(int j=i;j<=n;j++)
		{
			q.push(a[j]);
		}
		while(!q.empty())
		{
			if(vis[q.front()]==1)
			{
				while(s.top()!=q.front())
				{
					vis[s.top()]=0;
					s.pop();
				}
					
			}
			else
			{
				s.push(q.front());
			}
			vis[q.front()]=1;
			q.pop();
		}
		for(int t=1;t<=m;t++)
		{
			if(vis[t]==1)ans[t]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
