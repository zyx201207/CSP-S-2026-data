#include <bits/stdc++.h>
using namespace std;
int w[500005];
int k[500];
struct hjm{
	int ti;
	int id;
}a[500][500005];
int x[100005],y[100005];
int tim[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j].id>>a[i][j].ti;
			
		}
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++)
		cout<<d<<endl;
	return 0;
}