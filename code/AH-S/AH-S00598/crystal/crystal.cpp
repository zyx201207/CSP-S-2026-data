#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
long long n,m,a[maxn],ans=1;
long long b[maxn],s[maxn],k[maxn];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000)
	{
			for(int i=1;i<=n;i++)
				cin>>a[i];
			sort(a+1,a+n+1);
			for(int i=1;i<=n;i++)
			{
				    int x=0;
				    int f=m;
					for(int j=i;j>=1;j--)
						if(f>=(a[i]-a[j]))
						{
								int v=a[i]-a[j];
								f-=v;
								x++;
						}
					if(x>ans)
						ans=x;
			}
			cout<<ans<<"\n";
			return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		int d=a[2]-a[1],summ=0;
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]==d)
				summ++;
		if(summ==n-1)
		{
				ans=1;
				for(int i=1;i<=n;i++)
				{
						ans+=d*i;
						if(ans>m)
						{
								cout<<i-1<<"\n";
								return 0;
						}
				}
		}
		for(int i=2;i<=n;i++)
			b[i]=abs(a[i]-a[i-1]);
		for(int i=2;i<=n+1;i++)
			s[i]=s[i-1]+(i-1)*b[i];
		for(int i=1;i<=n;i++)
		k[i]=k[i-1]+a[i];
		for(int i=2;i<=n;i++)
		{
				int x;
				if(m>=s[i])
				{
					x=i;
					if(x>ans)
						ans=x;
				}	
				else
				{
					int l=1,r=i;
					int mid=(l+r)>>1;
					while(s[i]-mid*a[i]+k[mid]<m)
					{
							mid=(l+r)>>1;
							int g=s[i]-mid*a[i]+k[mid];
							if(g<m)
								mid=l+1;
							else
								mid=r-1;
					}
					while(a[mid]==a[mid-1])
						mid--;
					if(i-mid+1>ans)
						ans=i-mid+1;
				}
		}
			cout<<ans<<"\n";
		}
	return 0;
}
