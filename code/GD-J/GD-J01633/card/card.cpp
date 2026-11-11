#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500010],sum[500010];
stack<int> stk;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int oa=1;
	arr[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		if(arr[i]<arr[i-1]) oa=0;
	}
	if(oa==1)
	{
		for(int i=1;i<=n;i++)
		{
			sum[arr[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cout << sum[i] << ' ';
		}
	}
	else
	{
		
		int vis[500010];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				vis[j]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(vis[arr[j]]==0)
				{
					vis[arr[j]]=1;
					stk.push(arr[j]);
				}
				else
				{
					while(1)
					{
						if(stk.top()==arr[j])
						{
							cout << stk.top();
							break;
						}
						vis[stk.top()]=0;
						stk.pop();
					}
				}
			}
			while(stk.empty())
			{
				
				sum[stk.top()]++;
				stk.pop();
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout << sum[i] << ' ';
		}
	}
	return 0;
}
