#include <bits/stdc++.h>
using namespace std;
int n,m,a[5010],ans[5010];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		int vis[3010];
		memset(vis,0,sizeof(vis));
		for(int j=i; j<=n; j++)
		{
			if(vis[a[j]])
			{
				while(s.size() && s.top()!=a[j])
				{
					vis[s.top()]--;
					s.pop();
				}
			}
			else s.push(a[j]),vis[a[j]]++;
		}
		while(s.size()) ans[s.top()]++,s.pop();
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
}
