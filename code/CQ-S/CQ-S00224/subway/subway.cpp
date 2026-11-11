#include<bits/stdc++.h>
using namespace std;
int w[500010];
int k[500010];
int a[510][5010];
int t[510][5010];
int l[510];
int r[510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;i++)
	{
	//	for(int j=1;j<=;j++)
		cout<<w[l[i]]+w[r[i]]<<endl; 
	}
	return 0;
}
