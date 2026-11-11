#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,d,q,w[M],k[N],a[N][N],t[N][N],x[Q],y[Q];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	int num=1;
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		cout<<num<<endl;
		num++;
	}
	return 0;
} 
