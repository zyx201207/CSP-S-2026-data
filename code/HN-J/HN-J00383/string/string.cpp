#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int a,l=0;
	cin>>a;
	long long b[100],io=0,po=0;
	char c[100];
	for(int i=1;i<=a;i++)
	{
		cin>>b[i]>>c[i];
		io=b[i];
		if(i!=1 && b[i]==io)
		{
			io=b[i];
		}
		if(i>1 && b[i]!=io)
		{
			po=b[i];
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(c[i]!=c[i-1] && i!=1)
		{
			l=1;
			break;
		}
	}
	if(l==0)
	{
		cout<<0;
		return 0;
	}
	int g=0,u=a;
	l=1;
	for(int i=1;i<=a;i++)
	{
		u--;
		if(c[u]!=c[i])
		{
			g=1;
			break;
		}
		if(b[i]!=b[i-1] && i!=1)
		{
			l=0;
			break;
		}	
	}
	if(g==0 && l==1)
	{
		cout<<0;
		return 0;
	}
	g=0;
	char s;
	for(int i=1;i<=a;i++)
	{
		if(b[i]>g)
		{
			s=c[i];
			for(int i=1;i<=a;i++)
			{
				if(s==c[i])
				{
					g+=b[i];
				}
			}
			
		}
	}
	int z=0;
	for(int i=1;i<=a;i++)
	{
		if(c[i]!=s)
		{
			z+=b[i];
		}
	}
	if(g-z>=0)
	{
		cout<<z;
		return 0;
	}
	else
	{
		int qw=0;
		char f;
		for(int i=1;i<=a;i++)
		{
			if(b[i]>qw && c[i]!=s)
			{
				f=c[i];
				for(int i=1;i<=a;i++)
				{
					if(f==c[i])
					{
						qw+=b[i];
					}
				}
			}
		}
		cout<<z-qw;
		return 0;
	}
	return 0;
}
