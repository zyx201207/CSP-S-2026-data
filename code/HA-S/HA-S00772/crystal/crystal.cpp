#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long res = 0;
	char ch = getchar();
	bool tag = 0;
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-')
	{
		tag = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		res = (res << 3) + (res << 1) + ch - '0';
		ch = getchar();
	}
	if (tag) return -res;
	return res;
}
void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x >= 10) write(x/10);
	putchar(x%10+'0');
}
const int N = 500005;
long long n,m,a[N],ans,sum[N];
bool check(int x,int y)
{
	long long tot = a[y]*(y-x+1)-(sum[y]-sum[x-1]);
	return tot <= m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	n = read(), m = read();
	for (int i=1;i<=n;i++)
		a[i] = read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		sum[i] = sum[i-1] + a[i];
	ans = 1;
	for (int i=1;i<=n;i++)
	{
		int l = 1, r = i, res = 1;
		while (l <= r)
		{
			int mid = (l+r)>>1;
			if (check(mid,i))
			{
				res = i-mid+1;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (res > ans) ans = res;
	}
	write(ans); 
	return 0;
}
