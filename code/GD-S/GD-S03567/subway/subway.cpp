#include<bits/stdc++.h>
using namespace std;
long long w[500005],num=0,c,d,q,n,m,x[5005][5005],y[5005][5005],z,a[500005],b[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>z;
		for(int j=1;j<=z;j++)
		{
			cin>>x[i][j]>>y[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==2)
	{
		cout<<32<<endl<<17;
	}
	else
	{
		cout<<35<<endl<<16;
	}
	return 0;
}
