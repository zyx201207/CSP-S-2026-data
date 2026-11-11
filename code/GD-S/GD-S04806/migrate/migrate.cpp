#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxs=2e6+9;
int c;
ll t,n,d,a[maxs],s[maxs],f[maxs][2],sum=0,cnt=0,p,u=0,o;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		sum=0;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		s[1]=0;
		for(int i=2;i<=n;i++)
		{
			s[i]=a[i]-a[1];
		}
		for(int i=2;i<=n;i++)
		{
			if(s[i]-s[i-1]>d)
			{
				n=i-1;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			f[i][1]=0;
		}
		f[1][1]=1;
		f[1][0]=1;
		for(int i=1;i<=n;i++)
		{
			u=0;
			cnt=0;
			sum=0;
			p=i;
			for(int j=i+1;j<=n;j++)
			{
				sum=s[j]-s[p];
				if(sum<d)
				{
					if(i==1)
					{
						f[j][0]=cnt+f[i][0];
						f[j][1]++;
					}
					if(f[j][0]==cnt+f[i][0]+1) f[j][1]++;
					continue;
				}
				if(sum==d)
				{
					if(i==1)
					{
						f[j][0]=cnt+f[i][0];
						f[j][1]++;
					}
					if(f[j][0]==cnt+f[i][0]+1) f[j][1]++;
				}
				if(sum>d)
				{
					j--;
				}
				cnt++;
				p=j;
				sum=0;
			}
		}
		for(int i=1;i<=n+1;i++)
		{
			if(f[i][1]==2)
			{
				u++;
			}
		}
		cout<<u<<endl;
	}
	return 0;
}
