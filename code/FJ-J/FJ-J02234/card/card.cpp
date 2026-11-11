#include<bits/stdc++.h>
using namespace std; 
int a,b,d,m,g,x,y,c[200001],n[200001],v[200001];
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
		for(int i=1;i<=a;i++)
		{
			if(c[i]==1&&d!=0)
			{
				d=0;
				x=0;
				d++;
			}
			else if(c[i]==1)
			{
				d++;
			}
			if(c[i]==2&&x!=0)
			{
				x=0;
				d=0;
				x++;
			}
			else if(c[i]==2)
			{
				x++;
			}
		}
		if(x>0)
		{
			g++;
			x=0;
		}
		if(d>0)
		{
			y++;
			d=0;
		}
	}
	cout<<y<<" "<<g;
	return 0;
}
