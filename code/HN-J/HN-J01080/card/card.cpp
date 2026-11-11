#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout); 
	int n,m;
	cin>>n>>m;
	int c[10+n];
	int a[100010],b[100010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int q=1;q<=n;q++)
	{
	
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
			a[i]=0;
			for(int j=1;j<=i;j++)
			{
				if(b[i]==b[j+1])
				{
					for(int l=1;l<=i;l++)
					{
						a[l]=b[l];
						b[l]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			c[i]=b[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i];
	}
    return 0;
}

