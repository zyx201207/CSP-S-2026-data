#include<bits/stdc++.h>
using namespace std;

int a[100001],b,c[100001],d[100001][2000001],e,f,g,h;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>a[0]>>b;
	for(int i=0;i<b;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		{
			cin>>d[i][j];
		}
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			for(int ij=0;ij<a[i];ij++)
			{
				if(d[i][j]+c[i]>=d[i][ij])
				{
					g++;
				}
			}
		}
		cout<<g<<endl;
	}
	return 0;
}
