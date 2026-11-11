#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int C,T;
int n;
long long d;
long long a[N];
struct node
{
	long long v;
	long long sl;
}f[N];
int h,l;
long long q[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(C<=10)
		{
			for(int i=1;i<=n;i++)
			{
				f[i].v=0;
				f[i].sl=1;
				int la=i;
				h=l=1;
				q[1]=1;
				for(int j=i+1;j<=n;j++)
				{
					while(a[j]-a[la]>d)
					{
						q[h]-=f[la].sl;
						if(q[h]==0)h++;
						la++;
					}
					if(la==j)break;
					f[j].v=f[la].v+1;
					f[j].sl=q[h];
					if(f[j-1].v==f[j].v)q[l]+=f[j].sl;
					else q[++l]=f[j].sl;
					if(f[j].sl==2)ans++;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(11<=C&&C<=12)
		{
			if(n==1)
			{
				cout<<0<<'\n';
				continue;
			}
			long long num=a[2]-a[1];
			d/=num;
			if(d==0)
			{
				cout<<0<<'\n';
				continue;
			}
			if(d==1)
			{
				cout<<0<<'\n';
				continue;
			}
			cout<<max(0ll,n-2*d+1)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int j=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			if(j>i+1)
			{
				int k=upper_bound(a+1,a+n+1,a[j-1]+d)-a-1;
				int p=upper_bound(a+1,a+n+1,a[j-2]+d)-a-1;
				ans+=k-p;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
