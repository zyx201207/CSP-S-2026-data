#include<bits/stdc++.h>
using namespace std;
long long a,b,c=1,d[32],e=0,f[200001][32],g[31],m[10000000];
void z(int v,int x)
{
	if(v==b+1)
	{
		int h=0;
		for(int i=1;i<=31;i++)
		{
			if(g[i]<f[0][i])
			{
				h=1;
			}
			if(h==1)
			{
				g[i]=m[i];
			}
		}
		return ;
	}
	int k[32];
	for(int i=x+1;i<=a;i++)
	{
		for(int j=1;j<=31;j++)
		{
			k[j]=m[j];
		}
		for(int j=1;j<=31;j++)
		{
			if(f[0][j]==1&&f[i][j]==1)
			{
				m[j]=1;
			}
			else
			{
				m[j]=0;
			}
		}
		z(v+1,i);
		for(int j=1;j<=31;j++)
		{
			m[j]=k[j];
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);  
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=31;i++)
	{
		m[i]=1;
	}
	for(int i=1;i<=a;i++)
	{
		cin>>c;
		while(c>0)
		{
			d[++e]=c%2;
			c/=2;
		}
		for(int j=1;j<=31;j++)
		{
			m[31-j+1]=d[j];
		}
		for(int j=1;j<=31;j++)
		{
			d[j]=0;
		}
		e=0;
	}
	z(1,0);
	c=1;
	int l=0;
	for(int i=31;i>=1;i--)
	{
		l+=g[i]*c;
		c*=2;
	}
	cout<<l;
	return 0;
}
