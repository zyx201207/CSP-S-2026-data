#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005], ans[300005], s[300005];
int vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(register int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		int k=0;
		for(register int j=i;j<=n;j++)
		{
			if(vis[a[j]]>0)
				k=vis[a[j]];
			else 
			{
				s[++k]=a[j];
				vis[a[j]] = k;
			}
		}
		for(register int j=1;j<=k;j++)
			ans[s[j]]++;
	}
	for(register int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
