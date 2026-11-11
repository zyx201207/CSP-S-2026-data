#include<bits/stdc++.h>
#define N 2000010
#define LL long long
using namespace std;
int n, lft[N], rt[N] ,f[N], g[N] , rtcnt[N], lftcnt[N];
LL a[N], d, ans;

int aha()
{
	scanf("%d%lld", &n, &d);
	ans=0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		lft[i]=rt[i]=f[i]=g[i]=rtcnt[i]=lftcnt[i] = 0;
	}
	
	int l = 1, r = 0;
	while(r < n)
	{
		if(a[r+1]-a[l] > d)
		{
			l++;
		}
		else
		{
			rt[l] = r + 1;
			lft[r + 1] = l;
			if(r < n) r++;
		}
	}
	for(int i = 1; i<=n;i++)
	{
		if(rt[i]==0) rt[i] = n;
	}
	rt[n] = -1;
	for(int i = 1; i <= n; i++)
	{
		lft[rt[i]] = min(lft[rt[i]], i);
	}
	lft[1] = -1;
	
	
//	for(int i = 1; i<=n;i++)
//	{
//		cout<<lft[i]<<" "<<rt[i]<<endl;
//	}
	for(int i = 1; i <=n;i++)
	{
		if(i!=n)rtcnt[rt[i]] ++;
		if(i!=1)lftcnt[lft[i]] ++;
	}
	for(int i = n - 1; i >= 1; i--)
	{
//		i,i+1
		f[i+1]=1;
		if(rt[i+1] != rt[i]&&i!=n-1)
		{
			f[i+1] += (rt[i+1] - rt[i] - 1) + f[rt[i + 1]];
		}
	}
	for(int i = 2; i <= n; i++)
	{
		g[i-1]=1;
		if(lft[i-1]!=lft[i]&&i!=1)
		{
			g[i-1] += (lft[i]-lft[i-1]-1) + g[lft[i-1]];
		}
	}
	
	for(int i = 1; i<= n-1;i++)
	{
		if(lft[i+1]==i||rt[i]==i+1) continue;
		ans += g[lft[i+1]] * f[rt[i]] + ((rtcnt[i+1]-1>0)?(rtcnt[i+1]-1>0):0) * ((lftcnt[i]-1>0)?(lftcnt[i]-1>0):0);
	}
	cout<<ans<<'\n';
	return 0;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		aha();
		
	}
	return 0;
}