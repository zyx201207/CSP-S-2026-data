#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[502],a[500002][500002],t[500002][500002];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	if (1<=c && c<=3)
	{
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
		}
	}
	if (4<=c && c<=6)
	{
	}
	if (c==7 || c==8)
	{
	}
	if (9<=c && c<=11)
	{
	}
	if (12<=c && c<=15)
	{
	}
	if (16<=c && c<=19)
	{
	}
	if (c==20 || c==21)
	{
	}
	if (c==22 || c==23)
	{
	}
	if (c==24 || c==25)
	{
	}
	return 0;
}