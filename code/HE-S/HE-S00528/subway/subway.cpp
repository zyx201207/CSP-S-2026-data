#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int m1[50005],k1[10005],a[505][50005],t[505][5005],x[100],y[100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>m1[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k1[i];
		for(int j=1;j<=k1[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	return 0;
}
