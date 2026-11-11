#include<iostream>
using namespace std;
int w[500001],k[501],a[501][500001],t[501][500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int j=1;j<=n;j++)
	{
		cin>>k[j];
		for(int l=1;l<=k[j];l++)cin>>a[j][l]>>t[j][l];
	}
	for(int r=1;r<=q;r++)
	{
		int x,y;
		cin>>x>>y;
		int s=w[x]+w[y]+t[1][x]+t[1][y];
		cout<<s<<endl;
	}
}
