#include<bits/stdc++.h>
using namespace std;
const int M=500005,N=505;
int w[M],k[N];
int a[N][N],t[N][N];
int main()
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
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		if(x==y)cout<<w[x]<<endl;
	}
	return 0;
}
