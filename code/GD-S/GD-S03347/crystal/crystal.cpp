#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+5;
int n;
long long m;
long long sum[Maxn];
int ans=0;
int main ()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	scanf ("%d%lld",&n,&m);
	if (n<=5000)
	{
		long long a[5005];
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort (a+1,a+1+n);
		for (int i=1;i<=n;i++)
		{
			int cont=0,cnt=0;
			for (int j=i;j>=1;j--)
			{
				cont+=a[i]-a[j];
				if (cont>m)
				{
					break;
				}else{
					cnt++;
				}
			} 
			ans=max(ans,cnt);
		}
		printf ("%d",ans);
	}else{
		for (int i=1;i<=n;i++)
		{
			long long a;
			scanf ("%d",&a);
			sum[i]=sum[i-1]+a;
			int cnt=0;
			for (int j=i-1;j>=1;j--)
			{
				if ((i-j)*a-(sum[i]-sum[j])>m)
				{
					break;
				}else{
					cnt++;
				}
			}
			ans=max (ans,cnt);
		}
		printf ("%d",ans);
	}
	return 0;
} 
