#include<bits/stdc++.h>
using namespace std;

const long long MAX=2000010;
long long c=0,t=0,n=0,d=0;
long long x[MAX];
long long l=0,r=0;
long long ans=0;

void into()
{
	n=0;d=0;ans=0;r=0;l=0;
	for(long long i=0;i<MAX;i++)
	{
		x[i]=0;
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		into();
		cin>>n>>d;
		for(long long j=0;j<n;j++)
		{
			cin>>x[j];
			
		}
		for(long long j=1;j<n;j++)
		{
			if(x[j]-x[j-1]>d || j==(n-1))
			{
			
				
				r=j-1;
				if(j==(n-1))
				{
					r=j;
					
				}
				if((r-l)>2)
				{
					
					for(int q=l+2;q<=r;q++)
					{
						
						if(x[q]-x[l]>d && x[q]-x[q-2]<=d &&
						(q-l)%2!=0)
						{
							
							ans+=(r-q+1);
							break;
						}
					}
					l=j;
				}
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
