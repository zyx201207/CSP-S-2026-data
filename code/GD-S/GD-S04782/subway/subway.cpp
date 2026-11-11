#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,rute[505][25],w[500005],k[505],timi,t[500][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>rute[i][j]>>t[i][j];
		}
	}
	while(~--q)
	{
		int x,y,a1,b1,a2,b2;
		cin>>x>>y;
		int sum=w[x]+w[y];
		if(x==y)
		{
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(x==rute[i][j])
				{
					a1=i;a2=j;
				}
				if(y==rute[i][j])
				{
					b1=i;b2=j;
				}
				if(a1==b1)
				{
					i=n+1;j=k[i]+1;
				}
			}
		}
		sum=sum+t[a1][a2]+t[b1][b2];
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
