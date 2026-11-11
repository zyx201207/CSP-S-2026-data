#include<bits/stdc++.h>
using namespace std;
int aa[201000],ss[201000][51],sa,ff[201000],gg[201000],a,s,z,x,f,g,b,h;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>a>>s;
	f=a;
	for(int i=1;i<=a;i++)
	{
		cin>>z;
		aa[i]=z;
		ff[i]=i;
		x=0;
		while(z!=0)
		{
			x++;
			ss[i][x]=z%2;
			z=z/2;
		}
		b=max(b,x);
	}
	for(int i=b;i>=1;i--)
	{
		g=0;
		for(int j=1;j<=f;j++)
		{
			if(ss[ff[j]][i]==1)
			{
				g++;
				gg[g]=ff[j];
			}
		}
		if(g>=s)
		{
			h=h+pow(2,i-1);
			for(int j=1;j<=g;j++)
			{
				ff[j]=gg[j];
			}
			f=g;
		}
	}
	cout<<h;
}
