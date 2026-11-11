#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c,T,n,d,ans=0,x[2000005],r[2000005],p[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++)
		{
			long long j=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
			r[i]=j;
		}
		if(n<=5000)
		{
			for(long long i=1;i<=n;i++)
			{
				long long lst=i,a=r[i];
				for(long long j=i+1;j<=r[i];j++)
				{
					p[j]=1;
				}
				while(lst+1<=a)
				{
					for(long long j=r[a],k=a+1,s=0;j>=a+1;j--)
					{
						while(k-1>=lst+1&&r[k-1]>=j)
						{
							k--;
							s+=p[k];
						}
						p[j]=s;
						if(s==2)
						{
							ans++;
						}
					}
					lst=a,a=r[a];
				}
			}
			cout<<ans<<endl;	
			continue;		
		}
		for(long long i=1;i<=n;i++)
		{
			long long lst=i,a=r[i],x=2,y=1;
			if(r[i]-2>=i+1&&r[r[i]-2]==r[r[i]])
			{
				continue;
			}
			while(lst+1<=a&&x<=2)
			{
				if(x==2)
				{
					if(a-1>=lst+1)
					{
						ans+=r[a-1]-r[a-2];		
						if(r[a-1]==r[a]-1&&r[a]-1>=a+1)
						{
							x=1,y=1;
							if(r[r[a]-1]==r[r[a]])
							{
								break;
							}
						}
						if(r[a-1]==r[a])
						{
							x=1,y=2;
							if(r[r[a]-1]==r[r[a]])
							{
								break;
							}							
						} 
						if(r[r[a]-2]==r[r[a]])
						{
							break;
						}
					}		
					else
					{
						if(r[r[a]-2]==r[r[a]])
						{
							break;
						}
					}
				}
				else
				{
					if(y==2)
					{
						ans+=r[a]-r[a-1];
					}
					if(r[r[a]-1]==r[r[a]])
					{
						break;
					}
				}
				lst=a,a=r[a];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
