#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=0,n=0,m=0,d=0,q=0,k=0,zz=0,x=0,y=0;long long time=0,most=0,sdr=0;
	int w[508][505],ij[505][508];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i][0];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<2*k;j++)
		{
			cin>>zz;
			w[zz][i]=1;
			cin>>ij[i][zz];
			
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>x>>y;
		time=w[x][0]+w[y][0];
		for(int j=0;j<n;j++)
		{
			if(w[x][j]==1 && w[y][j]==1)
			{
				time=time+ij[j][x]+ij[j][y];
				if(time>=most)
				{
					most=time;
				}
				time=w[x][0]+w[y][0];
			}
			else
			{
				for(int v=0;v<m;v++)
				{
					if(w[x][j]==1 && w[v][j]==1 )
					{
						time=time+ij[j][x]+ij[j][v];
						if(time>=most)
						{
							most=time;
						}
						time=w[x][0]+w[y][0];
					}
					if(w[y][j]==1 && w[v][j]==1 )
					{
						time=time+ij[j][y]+ij[j][v];
						if(time>=sdr)
						{
							sdr=time;
						}
						time=w[x][0]+w[y][0];
					}
				
				}
				
			}
		}
		if(sdr!=0 && most!=0)cout<<most+sdr<<endl;
		else if(most!=0)cout<<most<<endl;
	}




	fclose(stdin);
	fclose(stdout);
	return 0;
} 
