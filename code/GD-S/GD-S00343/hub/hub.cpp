#include<bits/stdc++.h>
using namespace std;

int a[6],b,c[6],d[6][1000001],e,f,g;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>a[0]>>b;
	for(int i=0;i<b;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		{
			cin<<d[i][j];
		}
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			for(int ij=0;ij<a[i];ij++)
			{
				if(abs(d[i][j]-d[i][ij])<g)
				{
					g=abs(d[i][j]-d[i][ij]);
				}
			}
		}
		cout<<g<<endl;
	}
	return 0;
}
