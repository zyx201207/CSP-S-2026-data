#include <bits/stdc++.h>
using namespace std;
int w[50005];
int line[50005][20];
int a[505][50005];
int t[505][50005];
int x[10005],y[10005];
int jz[50005][505];
int hc[505][50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[m];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int o;
			cin >> o >> t[i][j];
			line[o][i]==1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			jz[j][i]=w[j]+t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> x[i] >> y[i];
		for(int j=1;j<=n;j++)
		{
			if(line[x[i]][j]==line[y[i]][j])
			{
				cout << jz[x[i]][j]+jz[y[i]][j] << endl;
				break;
			}
		}
	}
	return 0;
}
