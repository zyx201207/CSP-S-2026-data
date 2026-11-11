#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],vis[100001],aa[3];
int bi = -9999;

void dfs(int id)
{
	if(id == m + 1)
	{
		int y = (aa[1] && aa[2]);
		if(bi < y)
		{
			bi = y;
		}
		return;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(vis[i] == 0)
			{
				aa[id] = a[i];
				vis[i] = 1;
				dfs(id + 1);
				vis[i] = 0;
			}
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<bi;
	
	return 0;
}
