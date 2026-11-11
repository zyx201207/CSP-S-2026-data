#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q,z[500005],k[505],tr[505][50005][2];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=n;i++) cin >> z[i];
	for(int i = 1;i<=n;i++)
	{
		cin >> k[i];
		for(int j = 1;j<=k[i];j++)
			cin >> tr[i][j][0] >> tr[i][j][1];
	}
	while(q--)
	{
		int sta,en,ans;
		cin >> sta >> en;
		ans+=z[sta]+z[en];
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=k[i];j++)
			{
				if(tr[i][j][0]==sta||tr[i][j][0]==en) ans+=tr[i][j][1];
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
