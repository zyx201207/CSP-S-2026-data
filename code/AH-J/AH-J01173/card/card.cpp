#include<bits/stdc++.h>
using namespace std;
int p[100000];
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[100000],d[100000];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		d[i]=c[i];
	}
						for(int i=0;i<n;i++)
						{
								if(n>0){
								for(int y=0;y<i-1;y++)
								{
										d[y]=-1;
								}
								}
										for(int y=0;y<n;y++)
										{
											d[y]=c[y];
										}
		
										
		
										for(int y=i;y<n;y++)
										{
											for(int z=y-1;z>=0;z--)
											{
												if(d[z]==d[y])
												for(int j=d[z];j<d[y];j++)
												{
												d[j]=-1;
												}
											}
										}
		
		for(int y=0;y<n;y++)
		{
			if(d[y+1]>0)
			{
				p[d[y]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<p[i]<<" ";
	}
	return 0;
}
