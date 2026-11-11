#include <bits/stdc++.h>
using namespace std;
long long ans=0,num=100000000000,sum=0,x,y,p=0,c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505];
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		while(ans!=x)
		{
			for(int j=1;j<=m;j++)
			{
				for(int o=1;o<=k[j];o++)
				{
					if(j==x && a[j][o]==y)
					{
						cout<<t[j][o]+w[x]+w[y]+t[x][y];
					}
					else if(a[j][o]==y)
					{
						if(num<=t[j][o]+w[j])
						{
							ans=j;
							sum=o;
							num=t[j][o]+w[j];
						}
					}
				}
			}
			p+=num;
		}
		cout<<p+t[x][y]+w[x]<<'\n';
	}
}
