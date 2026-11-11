#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<int>t;
		int vis[300010];
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=1;
				t.push(a[j]);
			}
			else
			{
				while(!t.empty()&&t.top()!=a[j])
				{
					vis[t.top()]=0;
					t.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
