#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],cnt[300005];
bool vis[300005];

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
		stack<int> st;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				st.push(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				while(st.top()!=a[j])
				{
					st.pop();
				}
				st.pop();
				st.push(a[j]);
			}
		}
		while(!st.empty())
		{
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	
	return 0;
} 
