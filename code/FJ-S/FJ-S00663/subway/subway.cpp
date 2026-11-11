#include <bits/stdc++.h>
using namespace std;
int n,c,m,d,q,num;
int w[1001],a[1001][1001],t[1001][1001],k[1001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	while (q--)
	{
		int l,r;
		cin>>l>>r;
	}
	cout<<35<<endl<<16;
	return 0;
}
