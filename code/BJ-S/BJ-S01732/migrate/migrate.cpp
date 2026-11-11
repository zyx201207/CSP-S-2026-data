#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+5;

int a[N], L[N], R[N], vall[N], valr[N], dp1[N], dp2[N];

void work()
{
	int n,d;
	scanf("%lld %lld",&n,&d);
	for(int i=0;i<=n+1;i++)
		a[i]=L[i]=R[i]=vall[i]=valr[i]=dp1[i]=dp2[i]=0;

	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);

	int now=n;
	for(int i=n;i>=1;i--)
	{
		while(a[now]-a[i]>d)
			now--;
		R[i]=now;
		if(R[i]==R[i+1])
			valr[i]=valr[i+1]+1;
		else
			valr[i]=0;
	}

	now=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[now]>d)
			now++;
		L[i]=now;
		if(L[i]==L[i-1])
			vall[i]=vall[i-1]+1;
		else
			vall[i]=0;
	}

	for(int i=1;i<=n;i++)
	{
		if(R[L[i]]==i)
			dp1[i]=dp1[L[i]]+valr[L[i]]+1;
		else
			dp1[i]=1;
	}

	for(int i=n;i>=1;i--)
	{
		if(L[R[i]]==i)
			dp2[i]=dp2[R[i]]+vall[R[i]]+1;
		else
			dp2[i]=1;
	}

	for(int i=1;i<=n;i++)
		vall[i]++, valr[i]++, dp1[i]--, dp2[i]--;

	int ans=0;
	for(int i=1;i<n;i++)
	{
		int y=R[i], x=L[i+1];
		if(x<i && i+1<y && R[x]==i+1 && L[y]==i)
		{
			ans += valr[x]*vall[y];
			if(L[i]==x)
				ans += dp1[x]*vall[y];
			if(R[i+1]==y)
				ans += valr[x]*dp2[y];
			if(L[i]==x && R[i+1]==y)
				ans += dp1[x]*dp2[y];
		}
	}

	printf("%lld\n",ans);
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--)
		work();
	return 0;
}