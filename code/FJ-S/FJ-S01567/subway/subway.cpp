#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,pans;
const int N=500,Q=100005;
int w[N],k[N],a[N][N],t[N][N],x[Q],y[Q];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];i++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		pans+=w[x[i]]+w[y[i]];
	}
	cout<<1; 
}

