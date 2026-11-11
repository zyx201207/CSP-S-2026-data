#include<bits/stdc++.h>
using namespace std;
int w[1000001],k[1000001],a[10001][10001],t[10001][10001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j;
	long long c,n,m,d,q,x,y,x1,x2;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>k[i];
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	cin>>x>>y>>x1>>x2;
	cout<<w[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+w[3]<<endl;
	cout<<w[1]+t[1][1]+t[1][2]+w[2];
	return 0;
}
