#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int ans[m+10] = {};
	int a[n+10] = {};
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		int d[n+10] = {};
		int vis[m+5] = {};
		for(int j=i;j<=n;j++)
		{
			d[j] = a[j];
			if(vis[a[j]] == 1){
				int l = i;
				for(l;l<=j;++l)
				{
					if(d[l] == a[j]) break;
				}
				for(int k=l;k<j;k++)
				{
					vis[d[k]] = 0;
					d[k] = 0;
				}
			} 
			vis[a[j]] = 1;
		}
		for(int k=1;k<=m;k++)
		{
			if(vis[k] == 1) ans[k] += 1;
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
 } 
