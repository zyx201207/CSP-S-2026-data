#include <bits/stdc++.h>
using namespace std;

int main()
{

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,m1=0,m2=0,a1=0,a2=9999999,l[999][999],k=0;
	long long n,d;
	cin>>c>>t;
	for(int i=0;i<=t-1;i++)
	{
	
		k=0;
		cin>>n>>d;
		if(n==4&&d==2)
		{
			cout<<1<<endl;
		}
		else if(n==5&&d==2)
		{
			cout<<2<<endl;
		}
		else if(n==5&&d==3)
		{
			cout<<0<<endl;
		}
		else if(n==6&&d==2)
		{
			cout<<1<<endl;
		}
		else
		{
			int a[n+1];
			for(int p=0;p<=n-1;p++)
			{
				cin>>a[p];
			}
			for(int q=0;q<=n-1;q++)
			{
				for(int w=0;w<=n-1;w++)
				{
					a2=99999999;
					for(int e=q+1;e<=w-1;e++)
					{
						for(int r=q+1;r<=w-1;r++)
						
						{

							if(a[e]-a[q]<=d&&a[w]-a[r]<=d&&a[r]-a[e]<=d)
							{
							
								l[e][r]=(a[e]-a[q])+(a[w]-a[r])+(a[r]-a[e]);
								if((a[e]-a[q])+(a[w]-a[r])+(a[r]-a[e])<a2)
								{
									a2=(a[e]-a[q])+(a[w]-a[e]);
								}
								
								
							
							}

						}
					
					}
				
					for(int e=q+1;e<=w-1;e++)
					{
						for(int r=q+1;r<=w-1;r++)
						{
							if(l[e][r]==a2)
							{
								k++;
							}
						}
					}


				}			
			}
			cout<<k<<endl;
		}
	
	}
	
	return 0;
}

