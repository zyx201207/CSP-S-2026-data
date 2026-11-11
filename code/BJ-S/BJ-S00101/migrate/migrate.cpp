#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
LL x[2000005],vis[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        LL n,d;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        	cin >> x[i];
        LL ans = 0;
        for (int i = 1;i <= n;i++)
        {
        	int p = i,m = 0;
        	vis[++m] = i;
        	while (p < n)
        	{
        		int fir = p;
        		int pos = upper_bound(x+p, x+n+1, x[p]+d)-x-1;
        		if (x[n]-x[p] < d) p = n+1;
        		else p = pos;
        		if (fir == p) break;
                vis[++m] = p;
        	}
        	for (int j = 2;j < m;j++)
        	{
        		for (int k = vis[j]+1;k < vis[j+1];k++)
                {
                	int ps = lower_bound(x+1, x+n+1, x[k]-d)-x;
                	if (vis[j]-ps != 1) continue;
                	ans++;
                }
        	}
        }
        cout << ans << endl;
    }
	return 0;
}