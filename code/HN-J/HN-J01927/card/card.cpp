#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0,c=0;
	cin>>n>>m;
	int a[n]={0},b[m]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int q=0;q<n;q++)
	{	
	
		for(int i=0;i<=n;i++)
		{
			for(int g=i+1;g<=n;g++)
			{
				if(a[g]==a[i])
				{
					for(int h=0;h<g;h++)
					{
						
						a[h]=0;
						
					}
				}
			}		
		} 
		for(int w=0;w<n;w++)
		{
			c=a[w];
			b[c-1]+=1;
		}
		for(int i=0;i<=q;i++){
			a[i]=0;
		}
	}

	
	for(int i=0;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;	
} 
