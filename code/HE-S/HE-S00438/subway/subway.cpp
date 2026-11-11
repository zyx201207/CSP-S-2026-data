#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[100000];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	int k[26][100000],k2[26][100000];
	for(int i=0;i<n;i++)
	{
		cin>>k[i][0];
		k2[i][0]=k[1][0];
		for(int j=1;j<=k[i][0]-1;j++)
		{
			cin>>k[i][j]>>k2[i][j];
		}
	}
	int x[100000],y[100000];
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	int r[100000];
	for(int o=1;o<=q;++o);
	{
		int a=0,s=1;
		int j=x[s];
		while(j<=y[s])
		{
			int b=w[j]+w[y[s]];
			for(int z=0;z<n;z++)
			{
				for(int t=1;t<=k[z][0];t++)
				{
					if(k[z][t]==j)
					b+=k2[z][t];
					j=k[z][t];
				} 
			}
			if(b>a)
			{
				a=b;
			}
		}
		s++;
		cout<<a<<endl;
	} 
	return 0;
 } 
