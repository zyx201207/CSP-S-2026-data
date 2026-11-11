#include<bits/stdc++.h>
using namespace std;
long long a[4005][4005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,d,q,n,m;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=3*m;i++)
	{
		for(int j=1;j<=3*m;j++)
	    {
		    a[i][j]=1000000000000;
    	}
    	a[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i+m+m][m+i];
		a[m+m+i][i]=a[i][m+i];
	}
	for(int i=1;i<=n;i++)
	{
		int kkk;
		cin>>kkk;
		int last=0;
		for(int j=1;j<=kkk;j++)
		{
			int v,w;
			cin>>v>>w;
			a[v][v+m]=w;
			a[v+m][v]=w;
			if(last!=0)
			{
				a[last][v]=0;
				a[v][last]=0;
			}
			last=v;
		}
	}
	for(int k=1;k<=3*m;k++)
	{
		for(int i=1;i<=3*m;i++)
		{
			for(int j=1;j<=3*m;j++)
			{
				if(a[i][k]+a[k][j]<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		u+=m;
		u+=m;
		v+=m;
		v+=m;
		cout<<a[u][v]<<endl;;
	}
	return 0;
} 
