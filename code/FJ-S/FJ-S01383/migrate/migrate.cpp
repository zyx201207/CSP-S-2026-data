#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2111111],a,g,gg,dd,minn=11111111,e;
void man(int xx,int yy)
{
	if(xx==a)
	{
		if(yy<minn)
		{
			minn=yy;
		}
		if(yy==minn)
		{
			dd=1;
		}
		if(dd==1)
		{
			e=1;
		}
		return;
	}
	for(int k=xx+1;k<=a;k++)
	{
		if(x[k]-x[xx]<=d)
		{
			man(k,yy+1);
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<=n-1;j++)
		{
			for(int z=j+1;z<=n;z++)
			{
				a=z;
				man(j,0);
				if(dd==1&&e==0)
				{
					gg++;
				}
				dd=0;
				e=0;
				g=0;
			}
		}
		cout<<gg<<endl;
		gg=0;
	}
	return 0;
}
