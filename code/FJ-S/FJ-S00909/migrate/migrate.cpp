#include<bits/stdc++.h>
using namespace std;
int c,t,n,b[1000005],f[1000005],e[1000005];
long long d,a[1000005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=0;
			f[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n;
			while(l<r)
			{
				int mid=(l+r+1)/2;
				if(a[mid]-a[i]<=d)
				{
					l=mid;
				}
				else
				{
					r=mid-1;
				}
			}
			b[i]=l;
		}
		for(int i=1;i<=n;i++)
		{
			int l=1,r=i;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(a[i]-a[mid]<=d)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			f[i]=l;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int cnt=0,x=j,p=1;
				e[cnt]=i;
				while(b[e[cnt]]<j)
				{
					cnt++;
					e[cnt]=b[i];
				}
				while(f[x]>i)
				{
					if(f[x]!=e[cnt]-1)
					{
						p=0;
						break;
					}
					x=f[x];
				}
				if(cnt!=0&&p!=0)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
