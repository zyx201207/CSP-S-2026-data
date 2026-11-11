#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
int c,T,n;
ll d, x[2000010];
int l[2000010], r[2000010];
int lf[2000010];
int rf[2000010];
ll ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		int j = 1;
		for(int i=1; i<=n; i++)
		{
			scanf("%lld",&x[i]);
			while(x[i]-x[j] > d)
			{
				r[j] = i-1;
				j++;
			}
			l[i] = j;
		}
		while(j<=n)
		{
			r[j] = n;
			j++;
		}
		l[n+1] = n+1;
		for(int i=1; i<=n; i++)
		{
			if(l[i] < l[i+1]) lf[i] = lf[l[i]]+l[i+1]-l[i];
			else lf[i] = 1;
		}
		r[0] = 0;
		for(int i=n; i>=1; i--)
		{
			if(r[i] > r[i-1]) rf[i] = rf[r[i]]+r[i]-r[i-1];
			else rf[i] = 1;
		}
		ans = 0;
		for(int i=2; i<=n-1; i++)
		{
			if(r[i] <= i+1 || l[i+1] >= i) continue;
			ll al = l[i+2]-l[i+1], ar = r[i]-r[i-1];
			if(l[i] == l[i+1] && l[i] != l[i+2]) al += lf[l[i]]-1;
			if(r[i] == r[i+1] && r[i] != r[i-1]) ar += rf[r[i+1]]-1;
			ans += al*ar;
		}
		cout << ans << endl;
	}
	return 0;
}