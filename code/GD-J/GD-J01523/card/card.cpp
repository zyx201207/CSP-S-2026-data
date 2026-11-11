#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[550000];
int vis[550000];
int ans[550000];
stack<int>stk;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n<=10000)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				if (vis[a[j]]==1)
				{
					while (!stk.empty()&&stk.top()!=a[j])
					{
						vis[stk.top()]=0;
						stk.pop();
					}
					stk.pop();
				}
				vis[a[j]]=1;
				stk.push(a[j]);
			}
			while (!stk.empty())
			{
				vis[stk.top()]=0;
				ans[stk.top()]++;
				stk.pop();
			}
		}	
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			ans[a[i]]++;
		}
	}
	for (int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
