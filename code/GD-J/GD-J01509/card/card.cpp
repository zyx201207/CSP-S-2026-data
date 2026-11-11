#include<bits/stdc++.h>
using namespace std;
int a1[500005],b1[500005],c1[500005];
int main()
{
	//freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
	int n,m,a=0,c;
	cin>>n>>m;
	c=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
	}
	while(c--)
	{
		a++;
		int b=1;
		for(int i=a;i<=n;i++)
		{
			b1[b]=a1[i];
			for(int j=1;j<=b-1;j++)
			{
				if(b1[i]==b1[j])
				{
					for(int k=j+1;k<=b;k++)
					{
						b1[k]=0;
					}
					b=j;
					break;
				}
			}
			b++;
		}
		for(int i=1;i<=b-1;i++)
		{
			c1[b1[i]]++;
		}
		for(int i=1;i<=b;i++)
		{
			b1[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c1[i]<<" ";
	}
	return 0;
}
