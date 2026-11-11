#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],f,vis[500010],t[500010];
stack<int> stk;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]>a[i])
		{
			f=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[a[j]]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				vis[a[j]]=1;
				stk.push(a[j]);
			}
			else
			{
				while(stk.top()!=a[j])
				{
					vis[stk.top()]=0;
					stk.pop();
				}
			}
		}
		while(!stk.empty())
		{
			t[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}

