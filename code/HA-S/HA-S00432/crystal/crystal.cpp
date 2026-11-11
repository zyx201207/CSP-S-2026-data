#include<bits/stdc++.h>
using namespace std;
long long n,m,num=0;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{	
		long long z,y;
		long long c=m;
		long long ans=0;
		z=i-1;
		y=i+1;
		while(c>0&&(z>0||y<=n))
		{
		
			if((a[i]-a[z])>(a[y]-a[i])&&z>0&&y<=n)
			{
				if(c-(a[y]-a[i])>=0)
				{
					c-=(a[y]-a[i]);
					y++;
					ans++;
				}else{
					break;
				}
				
			}
			else{
				if((a[i]-a[z])<=(a[y]-a[i])&&z>0&&y<=n)
				{
					if(c-(a[i]-a[z])>=0)
					{
						
						c-=(a[i]-a[z]);
						z--;
						ans++;
					}
					else{
						break;
					}
					
				}
			
			else{
				if(z<=0&&y<=n)
				{
					if(c-(a[y]-a[i])>=0)
					{
						c-=(a[y]-a[i]);
						y++;
						ans++;
					}else{
						break;
					}
				}
		
			else{
				if(y>n&&z>0)
				{
					if(c-(a[i]-a[z])>=0)
					{
						c-=(a[i]-a[z]);
						z--;
						ans++;
					}else{
						break;
					}
				}
			}
		}
		}	}
		
		num=max(num,ans);
		
	}
	cout<<num+1;
	
	return 0;
}
