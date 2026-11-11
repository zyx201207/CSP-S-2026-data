#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[500010];
bool vis[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		if(k!=1)
		{
			memset(vis,0,sizeof(vis));
		}
		deque<int> q;
		for(int i=k;i<=n;i++)
		{
			if(vis[a[i]])
			{
				int t;
				do
				{
					t=q.back();
					q.pop_back();
					vis[t]=0;
				}while(t!=a[i]);
			}
			vis[a[i]]=1;
			q.push_back(a[i]);
		}
		for(int i=1;i<=m;i++) sum[i]+=vis[i];
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
