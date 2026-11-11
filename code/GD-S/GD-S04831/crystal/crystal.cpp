#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll N=5e5+10;
int n;
ull m;
ll a[N],b[N],cnt[N],l[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("ctrstal.out","w",stdout);
	scanf("%d%llu",&n,&m);
	int res=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
		if(a[i]==a[i-1])cnt[res]++;
		if(a[i]!=a[i-1])
		{
			b[res]=a[i];
			res++;
			cnt[res]=1;
		}
		if(res>1)
		{
			if(b[res-1]<0&&b[res]<0)
			{
				l[res-1]=-1*(b[res-1]+b[res]);
			}
			else
			{
				l[res-1]=b[res]-b[res-1];
			}
		}
	}
	int mn=-1000;
	for(int i=n;i>1;i--)
	{
		int sum=0;
		for(int j=i-1;j>=1;j--)
		{
			if(m<=l[j])
			{
				j=0;
				continue;
			}
			else if(cnt[j]*l[j]<=m)
			{
				sum+=cnt[j];
				m-=cnt[j]*l[j];
			}
			else
			{
				for(int k=cnt[j]-1;k>=1;k--)
				{
					if(k*l[j]<=m)
					{
						sum+=k;
						m-=k*l[j];
						k=0;
						continue;
					}
				}
			}
			mn=max(mn,sum);
		}
	}
	printf("%d\n",mn);
	return 0;
}
