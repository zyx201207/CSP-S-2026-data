#include<bits/stdc++.h>
using namespace std;

int a[200000];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			if(0 and i>max)
			{
				max=0 and i;
			}
		}
		cout<<max;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i and j>max)
				{
					max=(i and j);
				}
			}
		}
		cout<<max;
	}
	return 0;
}
