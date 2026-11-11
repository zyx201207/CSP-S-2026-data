#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n,m,x=0,y=1;
	int a[50000];
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i!=0;i++)
	{
		if(m==0)
		{
			break;
		}
		if(a[x]<a[x+1])
		{
			a[x]=a[x]+1;
			m=m-1;
				if(m==0)
			{
				break;
			}
			if(x!=0)
			{
				for(int j=x;j!=0;j--)
				{
					if(m==0)
					{
						break;
					}
					a[j-1]=a[j-1]+1;
					m=m-1;
				}
			}
		}
		else
		{
			x++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			y=y+1;
		}
	}
	cout<<y<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
