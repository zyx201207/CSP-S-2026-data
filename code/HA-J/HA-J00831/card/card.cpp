#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l,r,tot=1,j;
int v[300005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		stack<int> stk;
		memset(v,0,sizeof(v));
		for(int j = i;j<=n;j++)
		{
			
			if(v[a[j]])
			{
				while(stk.top()!=a[j])
				{
					v[stk.top()]=0;
					stk.pop();
				}
				stk.pop();
			}
			v[a[j]]=1;
			stk.push(a[j]);
		}
		while(!stk.empty())
		{
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
