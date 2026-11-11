#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<long long> a;
vector<short> b(1e6);
int ans,maxx=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%d %d",&n,&d);
		a.resize(n+1);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				int y = abs(a[j]-a[i]);
				if(y<d)
				{
					b[y]++;
					maxx = max(maxx,y);
				}
			}
		}
		for(int i=0;i<=maxx;i++)
		{
			if(b[i])
			{
				while(1==1)
				{
					if(b[i]>=2)
					{
						ans++;
						b[i]/=2;
					}
					else
					{
						break;
					}
				}
				
			}
			continue;
		}
		printf("%d\n",ans-n/2);
		ans=0;
	}
	return 0;
}
