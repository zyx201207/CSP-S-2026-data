#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int x[N], r[N], l[N], t1[N], t2[N], is[N], r1[N], r2[N], w1[N], w2[N], ans;

int get(int i, int t)
{
	if(t==1) return w1[i] - w1[r1[i]];
	return w2[i] - w2[r1[i]] + w1[r1[i]] - w1[r2[i]];
}

void slv(int L, int R)
{
	int i;
	for(i=L;i<=R;i++)
	{
		if(i>L) t1[i] = r[r[i]] - r[r[i]-1];
		if(r[i]>i+1&&l[r[i]-1]==i) t2[i] = r[r[i]-1] - max(r[r[i]-2],r[i]);
		if(r[i]!=R)
		{
			is[i] = r[i] - l[r[r[i]]];
			if(is[i]>=2||(is[i]==1&&l[r[i]-1]!=i)) is[i] = 2;
		}
	}
	// printf("%lld %llddd\n", t2[1], t2[2]);
	for(i=R-1,r1[R]=r2[R]=R;i>=L;i--)
	{
		w1[i] = t1[i] + w1[r[i]], w2[i] = t2[i] + w2[r[i]];
		r1[i] = r1[r[i]], r2[i] = r2[r[i]];
		if(is[i]>=2) r2[i] = r[i];
		if(is[i]==1) r1[i] = r[i], r2[i] = r1[r[i]];
		r1[i] = min(r1[i],r2[i]);
		if(r[r[i]-1]>r[i]) ans += r[r[i]-1] - max(r[r[i]-2],r[i]);
		if(r[i]!=R)
		{
			if(r[i]>i+2&&r[r[i]-2]>=r[r[i]]) continue;
			if(r[i]>i+1&&r[r[i]-1]>=r[r[i]]) ans += get(r[i],1);
			else ans += get(r[i],2);
		}
		// printf("%lld %lld %lld\n", i, ans, get(r[i],1));
	}
	// printf("slv %lld %lld %lld %lld\n", L, R, t2[3], t2[r1[1]]);
}

int Main()
{
	int n, d, i, j;
	scanf("%lld%lld", &n, &d);
	for(i=1;i<=n;i++) scanf("%lld", &x[i]);
	for(i=j=1;i<=n;i++)
	{
		while(j<=n&&x[j]-x[i]<=d) j++;
		r[i] = j - 1;
	}
	for(i=j=n;i>=1;i--)
	{
		while(j>=1&&x[i]-x[j]<=d) j--;
		l[i] = j + 1;
	}
	// for(i=n;i>=1;i--) if(i==n||x[i]+d<x[i+1]) to[i] = i;else to[i] = to[i+1];
	int lst = n;
	for(i=n-1;i>=0;i--) if(x[i]+d<x[i+1]||i==0) slv(i+1,lst), lst = i;
	printf("%lld\n", ans);
	for(i=1;i<=n;i++) x[i] = l[i] = r[i] = t1[i] = t2[i] = is[i] = r1[i] = r2[i] = w1[i] = w2[i] = 0;
	ans = 0;
	return 0;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	scanf("%lld%lld", &c, &t);
	while(t--) Main();
	return 0;
}