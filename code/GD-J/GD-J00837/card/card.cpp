#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int a,b,z=0;
	cin >> a >> b;
	int c[a],d[b+1]={0},y[a],x[b+1]={0};
	for(int e=0;e<a;e++)
	{
		cin >> c[e];
		y[e]=c[e];
	}
	for(int e=0;e<a;e++)
	{
		for(int f=z;f<a;f++)
		{
			for(int g=f+1;g<a;g++)
			{
				if(c[g]==c[f])
				{
					for(int h=f;h<g;h++)
					{
						c[h]=0;
						f+=g-f;
					}
				}
			}
		}
		for(int f=z;f<a;f++)
		{
			x[c[f]]+=1;
			c[f]=y[f];
		}
		for(int f=1;f<=b;f++)
		{
			if(x[f]>0)
			{
				d[f]=1;
			}
			x[f]=0;
		}
		z++;
	}
	for(int e=0;e<b;e++)
	{
		cout << d[b] << " ";
	}
	return 0;
}
