#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=30;
int a[N],cnt[M];
bool v[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	m=n-m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		v[i]=1;
		for(int j=0;j<30;j++)
		{
			if(a[i]&(1<<j))
			{
				cnt[j]++;
			}
		}
	}
	int sum=0,lst=n,ans=0;
	for(int j=29;j>=0;j--)
	{
		if(cnt[j])
		{
			if(sum+lst-cnt[j]>m)
			{
				continue;
			}
			sum+=lst-cnt[j];
			ans+=(1<<j);
			for(int i=1;i<=n;i++)
			{
				if(v[i]&&!(a[i]&(1<<j)))
				{
					v[i]=0;
					lst--;
					for(int k=j-1;k>=0;k--)
					{
						if(a[i]&(1<<k))
						{
							cnt[k]--;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
