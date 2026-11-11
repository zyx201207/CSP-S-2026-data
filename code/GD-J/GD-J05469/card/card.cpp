#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	stack<int> st;
	int n,m;
	cin>>n>>m;
	int vis[m+1];
	int ans[m+1];
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		while(!st.empty())st.pop();
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]!=0)
			{
				while(st.top()!=a[j])
				{
					vis[st.top()]--;
					st.pop();
				}
			}
			else
			{
				st.push(a[j]);
				vis[st.top()]++;
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
