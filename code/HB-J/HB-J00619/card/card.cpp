#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];//card 
long long t[500005];//table
long long f[300005];//if appear in table now
long long book[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		memset(t,0,sizeof t);
		long long len=0;
		for(long long j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				len++;
				t[len]=a[j];
				f[a[j]]=1;
			}
			else
			{
				for(long long k=1;k<=len;k++)
				{
					if(t[k]==a[j])
					{
						for(long long p=k;p<=len;p++)
						{
							f[t[p]]=0;
						}
						len=k-1;
						len++;
						t[len]=a[j];
						f[a[j]]++;
					}
				}
			}
			
		}
		for(long long j=1;j<=len;j++)
		{
			book[t[j]]++;
		}
	}
	for(long long i=1;i<=m;i++) printf("%lld ",book[i]); 
	return 0;
}
