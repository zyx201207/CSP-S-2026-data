#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n,m;
	int k=0;
	int f=0,g=0;
	int a[500005];
	int b[500005];
	int c[500005];
	int d[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(b[i]>1)
			{
				if(a[i]==i)
				{
					g=a[i];
					k++;
					if(k==2)
					{
						f=i;
						for(int h=g;h<=f;h++)
						{
							a[h]=0;
						}
					}
				}
			}
			for(int r=0;r<n;r++)
			{
				if(a[i]!=0)
				{
					c[a[i]]++;
				}
			}
		}
		if(c[i]>0)
		{
			d[c[i]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
}
