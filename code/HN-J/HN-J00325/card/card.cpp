#include<bits/stdc++.h>
using namespace std;
int prev[500005],C[500005],W[300005],n,m,a[500005],ans[300005];
bool vis[500005],Vis[500005];
vector<int>X[500005];
int dfs(int u)
{
	Vis[u]=1;
	int R=1;
	for(int i=0;i<X[u].size();i++)
	{
		int v=X[u][i];
		if(!Vis[v])
		{
			R=R+dfs(v);
		}
	}
	ans[a[u]]=max(ans[a[u]],R);
	return R;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		prev[i]=W[a[i]];
		W[a[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		int k=i;
		while(k>0)
		{
			vis[k]=1;
			if(prev[k]!=0)
			{
				X[prev[k]].push_back(k);
				k=prev[k];
			}
			else
			{
				X[k-1].push_back(k);
				k--;
			}
			if(vis[k])
			{
				break;
			}
		}
	}
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
