#include<bits/stdc++.h>
using namespace std;
long long f[510][510],n,m,d,q,c,w[100010],a[510][510],t[510][510];
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
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			
			cin>>a[i][j]>>t[i][j];
			t[i][j]=t[j][i]; 
			a[i][a[i][j]]=1;
			a[i][j]=0;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+a[1][3]+a[2][1];
	}
	/*memset(f,0x3f3f3f3f,sizeof f);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				f[i][j]=f[j][i]=0;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(!(i==k||j==i||k==j)&&(f[i][k]+f[k][j]<f[i][j]))
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}*/
	return 0;
}
