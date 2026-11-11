#include<bits/stdc++.h>
using namespace std;
int T,t;
long long n,k,cnt,sum;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&T,&t);

    while (t--)
    {
    	sum = 0;
    	cnt = 0;
    	scanf("%lld%lld",&n,&k);
    
    	for (int i=1;i<=n;i++)
    	{
    		scanf("%lld",&a[i]);
    
		}

		int ff = 0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]>=a[1] + k)
			{
				ff = i;
				break;
			}
		}
		for (int i=ff+1;i<=n;i++)   //以i为终点 
		{
			for (int j=1;j<=i;j++)
			{
				long long c = (a[i]-a[j])/k + (a[i]-a[j])%k;  //**飞行次数 
				if (c>=2)
				{
					int u = (a[i]-a[j])/k;
					int p = a[i]-a[j]-(u-1)*k;
					cnt = 0;
					for (int kk=p/2;kk<=p;kk++)
					{
						if (kk<=k && (p-kk)<=k)
						{
							cnt ++;
						}
					}
					
					if (cnt == 2)  sum ++;
				}
			}
		}
		printf("%lld\n",sum);
//		cout << sum << endl;
	}
    return 0;
}

