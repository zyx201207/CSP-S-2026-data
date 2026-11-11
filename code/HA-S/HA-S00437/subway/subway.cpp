#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
int c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x,y,f[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	f[1][1]=0;
	for(int i=1;i<=2;i++)
	{
		cin>>k[i];
		for(int j=2;j<=2*k[i]+1;j++)
		{
			cin>>a[i][j]>>t[i][j];
			f[i][j]=max(f[i][j],f[i][j-1]+a[i][j]+t[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<f[i][2*k[i]+1]<<"\n";
	}
	return 0;
}
