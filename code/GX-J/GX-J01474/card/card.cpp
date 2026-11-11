#include<bits/stdc++.h>
using namespace std;
long long a,b,c[10000000],d[10000000],e[10000000];
int main()
{
	freopen("card.in","r",stdin);  
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
			if(d[c[j]]==0)
			{
				d[c[j]]=j;
			}
			else
			{
				for(int z=d[c[j]];z<=j;z++)
				{
					d[c[z]]=0;
				}
				d[c[j]]=j;
			}
		}
		for(int z=1;z<=b;z++)
		{
			if(d[z]!=0)
			{
				e[z]++;
			}
			d[z]=0;
		}
	}
	for(int z=1;z<=b;z++)
	{
		cout<<e[z]<<" ";
	}
	return 0;
}
