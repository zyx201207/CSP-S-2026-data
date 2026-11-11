#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],d[500005];
int main()
{
	//freopen(card.in"r"stdin);
	//freopen(card.out"w"stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int c=0;
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i];
	}
	for(int x=1;x<=n;x++)
	{
		
		for(int i=1;i<=n;i++)
		{
			
			for(int j=1;j<=m;j++)
			{
				
				if(a[i]==j)
				{
					
					
					for(int s=1;s<=j-1;s++)
					{
						if(d[j]==d[s])
						{
							for(int r=1;r<=j;r++)
							{
								for(int t=j;t<=n;t++)
								{
									d[r]=d[t];
								}
								
							}
						}
						}	
						c++;
						b[j]++;
						for(int i=1;i<=m;i++)
						{
							cout<<b[i]<<" ";
						}
						cout<<endl;
					
					
				}
			}
			
			
		}c=0;
		for(int j=1;j<=n;j++)
			{
				a[j]=a[j+1];
			}
	}

	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
	 
}
