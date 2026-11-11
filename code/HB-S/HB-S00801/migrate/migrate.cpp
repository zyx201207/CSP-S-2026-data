#include<bits/stdc++.h>
using namespace std;
const int M=2000005;
long long c,t,n,d;
int a[M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==3)cout<<0<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int f=0;
				long long way=0,min_way=0,p=a[i],noway=0;
				for(int k=i+1;k<=j;k++)
				{
					if(p+d<a[k])
					{
						noway=1;
						break;
					}
					else
					{
						int brk=1;
						while(brk==1)
						{
							if(p+d>=a[k+1])k++;
							else brk=0;
						}
						p+=d;
						min_way++;
					}
				}
				if(noway==1)
				{
					f=1;
				}
				else
				{
					for(int k=i;k<=j;k++)
					{
						long long way1=1;
						for(int l=i+1;l<=j;l++)
						{
							int brk=1;
							long long p=a[l];
							while(brk==1)
							{
								if(p+d>=a[l+1])l++;
								else brk=0;
							}
							p+=d;
							way1++;
						}
						if(way1==min_way)way++;
					}
					if(way!=2)
					{
						f=1;
					}
				}
				if(f==0)
				{
					ans++;
				}
			}
		}
		cout<<endl<<ans;
	}
	return 0;
}
