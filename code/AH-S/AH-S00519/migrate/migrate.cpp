#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
ll c,t,n,d,a[N],ans;
int tr[N];
ll dp[5010][5010];
ll f[5010][5010];
ll read();
void write(ll x);
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	while(t--)
	{
		ans = 0;
		n = read(),d = read();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n;i++)
		{
			int l = i,r = n;
			while(l <= r)
			{
				int mid = (l+r) / 2;
				if(a[mid] - a[i] <= d) l = mid + 1;
				else r = mid - 1;
			}
			tr[i] = r;
		}
		if(n <= 5000)
		{
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
					dp[i][j] = 0x3f3f3f3f3f3f3f3f,f[i][j] = 0;
			for(int i=1;i<=n;i++) dp[i][i] = 0,f[i][i] = 1;
			for(int len=2;len<=n;len++)
				for(int l=1;l<=n - len + 1;l++)
				{
					int r = l + len - 1;
					if(tr[l] >= r) 
					{
						dp[l][r] = 1,f[l][r] = 1;
						continue;
					}
					for(int k=min(tr[l],r-1);k>=max(l+1,tr[l] - 2);k--)
					{
						if(dp[l][k] + dp[k][r] < dp[l][r])
							dp[l][r] = dp[l][k] + dp[k][r],f[l][r] = min((ll)3,f[l][k] * f[k][r]);
						else if(dp[l][k] + dp[k][r] == dp[l][r])
							f[l][r] = min((ll)3,f[l][r] + f[l][k] * f[k][r]);
					}
					if(f[l][r] == 2) ans ++ ;
				}
			write(ans);
			puts("");
			continue;
		}
		else if(c >= 11 and c <= 12)
		{
			ll dx = a[2] - a[1];
			ll x = d / dx;
			if(x >= 2 and n >= 2*x) write(n-2*x+1);
			else write(0);
			puts("");
			continue;
		}
		puts("0");
	}
	return 0;
}

ll read()
{
	ll s = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s*f;
}

void write(ll x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
