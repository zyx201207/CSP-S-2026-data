#include<bits/stdc++.h>
using namespace std; 
int a,b,d,m,g,c[200001],n[200001],v[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b; 
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	if(b==1)
	{
		for(int i=1;i<=a;i++)
		{
			m=max(c[i],m);
		}
		cout<<m;
		return 0;
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(i==j)
					{
						break;
					}
				for(int l=1;l<=a;l++)
				{	
					if(c[i]%2==1&&c[j]%2==1)
					{	
						g=g+(l*2)-1;
					}
					c[i]=c[i]/2;
					c[j]=c[j]/2;
				}
			}
			m=max(g,m);
			g=0;
		}
	}
	cout<<m;
	return 0;
}
