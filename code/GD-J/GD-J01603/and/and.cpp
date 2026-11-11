#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read();
const int N = 1e7 + 10;
int cnt[N], ch[N][3], p[N];
ll idx = 0, sum = 1, ans = 0;
ll n, m;

inline void insert(ll x)
{
	int k = 0;
	for(int i = 31; i >= 0; i--)
	{
		int now = ((x >> i) & 1);
		if(!ch[k][now]) ch[k][now] = ++idx;
		k = ch[k][now];
		cnt[k]++;
	}
}

void query()
{
	for(int i = 31; i >= 0; i--)
	{
		int len = 0;
		for(int j = 1; j <= sum; j++)
		{
			if(ch[p[j]][1]) len += cnt[ch[p[j]][1]];
		}
		if(len >= m)
		{
			for(int j = 1; j <= sum; j++)
			{
				p[j] = ch[p[j]][1];
			}
			ans |= (1 << i);
		}
		else
		{
			int last = sum;
			for(int j = 1; j <= last; j++)
			{
				if(ch[p[j]][1])
				{
					if(ch[p[j]][0]) p[++sum] = ch[p[j]][0];
					p[j] = ch[p[j]][1];
				}
				else if(ch[p[j]][0]) p[j] = ch[p[j]][0];
			}
		}
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) insert(read());
	query();
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
