#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

typedef long long ll;

ll a[N],b[N];
int vis[N];
stack<int>q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ll n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				while(q.top()!=a[j])
				{
					vis[q.top()]=0; 
					q.pop();
				}
			}
			else
			{
				vis[a[j]]=1;
				q.push(a[j]);
			}
		}
		while(!q.empty())
		{
			b[q.top()]++;
			q.pop();
		} 
	}
	
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';

	return 0;
}

