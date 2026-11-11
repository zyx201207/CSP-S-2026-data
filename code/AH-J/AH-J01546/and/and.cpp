#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],amax,w,c[35],ans,r[35],d[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	r[1]=1;
	for(int i=2;i<=30;i++)
	{
		r[i]=r[i-1]*2;
	}
	for(int eee=30;eee>0;eee--)
	{
		for(int i=1;i<=30;i++)
		{
			c[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=d[i];
		}
		for(int i=1;i<=n;i++)
		{
			int j=1;
			while(a[i])
			{
				c[j++]+=a[i]%2;
				a[i]/=2;
			}
		}
		for(int i=30;i>=1;i--)
		{
			if(c[i]>=m)
			{
				ans+=r[i];
				for(int j=1;j<=n;j++)
				{
					if(d[j]>r[i])
					d[j]=d[j]%r[i];
					else
					d[j]=0;
				}
				break;
			}
		}
	}
	cout<<ans;
}
