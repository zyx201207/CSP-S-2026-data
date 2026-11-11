#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, d;
int a[2000005], num[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		int ans = 0;
		scanf("%lld%lld",&n,&d);
		for(int i = 1; i <= n; i++)
			scanf("%lld",&a[i]);
		if(c==11 || c==12)
		{
			
		}else if(c==13||c==14)
		{
			
		}else{
			for(int i = 1; i <= n; i++)
			{
				for(int j = i+1; j <= n; j++)
				{
					if(a[j] - a[i] <= d || a[j] - a[i] > 2 * d) continue;
					int pos1 = lower_bound(a+1,a+1+n,a[j]-d) - a;
					int pos2 = upper_bound(a+1,a+1+n,a[i]+d) - a - 1;
				//	cout << i << " " << j << " " << pos1 << " " << pos2 << "\n";
					if(pos2 - pos1 + 1 == 2)
					{
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
 
