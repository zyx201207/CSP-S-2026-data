#include <bits/stdc++.h>
using namespace std;

long long l[10005][10005],a[10005][10005];
int c,n,m,d,q,ki,w[10005],x,y;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for (int i=1;i<10005;i++)
	{
		for (int j=1;j<10005;j++)
		{
			l[i][j]=1e18;
		}
	}
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
	{
		cin >> w[i]; 
	}
	for (int i=1;i<=n;i++)
	{
		cin >> ki;
		for (int k=1;k<=ki;k++)
		{
			int v,t;
			cin >> v >> t;
			a[i][k]=t;
			a[k][i]=t;
		}
		for (int k1=1;k1<=ki;k1++)
		{
			for (int k2=k1+1;k2<=ki;k2++)
			{
				l[k1][k2]=min(a[i][k1]+a[i][k2],l[k1][k2]);
				l[k2][k1]=l[k1][k2];
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=1;k<=m;k++)
			{
				if (a[i][k]!=0 && a[j][k]!=0)
				l[i][j]==min(l[i][j]+a[i][k]+a[j][k],l[i][j]);
			}
		}
	}

	for (int i=1;i<=q;i++)
	{
		cin >> x >> y;
		cout << l[x][y]+w[x]+w[y] << endl;
	}
	
	return 0;
}
