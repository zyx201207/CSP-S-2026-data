#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
stack<int> q;
int a[N],vis[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
			vis[j]=0;
		for(int j=i; j<=n; j++)
		{
			if(!vis[a[j]])
			{
				vis[a[j]]=1;
				q.push(a[j]);
			}
			else
			{
				while(q.top() != a[j])
				{
					vis[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<" ";
	return 0;
}
