#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,sum[N],a[N],ans[N],l,r;
bool bo[N],vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		if(bo[k])
		continue;
		memset(vis,0,sizeof(vis));
		stack<int> q;
		int x=1;
		bo[k]=1;
		for(int i=k;i<=n;i++)
		{
			if(sum[a[i]]>i)
			{
				i=sum[a[i]]-1;
				continue;
			}
			if(vis[a[i]])
			{
				while(q.top()!=a[i])
				{
					vis[q.top()]=0;
					q.pop();
				}
				l=i+1;
			}
			else
			{
				q.push(a[i]);
				vis[a[i]]=1;
			}
		}
		while(q.size())
		{
			ans[q.top()]+=x;
			q.pop();
		}
		sum[a[k]]=k;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 
