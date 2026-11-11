#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i=0,a=0,s=0,d=0,f=0,g=0,l=0,ll=0,x=0,k=1;

	cin>>a;
	int y[a];
	cin>>s;
	for(i=0;i<a;i++)
	{
		cin>>y[i];
	}
	for(i=0;i<a;i++)
	{
		for(d=0;d<a;d++)
		{
			if(y[d]<=y[d+1])
			{
				f=y[d+1];
				y[d+1]=y[d];
				y[d]=f;
			}
		}
	}
	while(y[s-1]>0)
	{
		for(i=0;i<s;i++)
		{
			if(y[i]%2==y[i+1]%2)
			{
				g++;
			}
			else{
				for(d=0;d<s;d++)
				{
					y[d]/=2;
					
				}
				l++;
				break;
				
			}
			if(g==s-1)
			{
				
				if(i==1)
				{
					ll++;
				for(d=0;d<s;d++)
					{
						y[d]/=2;
					
					}
				l++;
				}
				else{
				
					for(x=1;x<l;x++)
					{
						k*=2;
					}
					ll+=k;
					k=1;
					for(d=0;d<s;d++)
					{
						y[d]/=2;
						
					}
					l++;
				}
				g=0;
				break;
			}
			
		}	
	}
	cout<<ll;
	
	return 0;	
}
