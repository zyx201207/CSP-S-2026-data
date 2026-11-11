#include<iostream>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long ans=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=k;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(i+3<=j)
					{
						long long len=0;
						for(int kk=1;kk<=j-3;kk++)
						{
							if((a[kk+3]-a[kk])>d&&(a[kk+2]-a[kk])<=d)
							{
								len++;
							}
						}
						if(len==1)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
