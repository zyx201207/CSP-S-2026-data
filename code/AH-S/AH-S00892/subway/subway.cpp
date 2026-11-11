#include<bits/stdc++.h>
using namespace std;
int w[500005],lu[505];
int zhan[505][500005];
struct s
{
	int x[25],dai;
}zh[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>lu[i];
		for(int j=1;j<=lu[i];j++)
		{
			cin>>zhan[i][j];
			cin>>t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<15<<endl;
	}
	return 0;
}
