#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],nw,g[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		nw = 0;
		for (int j = i;j <= n;j++)
		{
			if (!f[a[j]] || f[a[j]] > nw) g[++nw] = a[j],f[a[j]] = nw;
			else nw = f[a[j]];
		}
		for (int j = 1;j <= nw;j++) ans[g[j]]++;
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
