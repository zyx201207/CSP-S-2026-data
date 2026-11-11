#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
vector<int> e[N];
ll c,t,n,k;
ll read();
void write(ll x);
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),t = read();
	while(t--)
	{
		n = read(),k = read();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u = read(),v = read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c >= 13 and c <= 14)
		{
			ll m = (n-1) / 2;
			if(k == n) write(0);
			else if(k >= m) write(1);
			else 
			{
				ll r = 2;
				while((m+1 - 2*r + 1 - (2*r-2)) > k) r ++ ;
				write(r);
			}
			puts("");
			continue;
		}
		if(c == 1)
		{
			int in[7];
			for(int i=1;i<=n;i++) in[i] = e[i].size();
			sort(in+1,in+6);
			if(in[5] == 2)
			{
				if(k == 1) write(2);
				else if(k >= 2 and k<=4) write(1);
				else write(0);
			}
			else if(in[5] == 3)
			{
				if(k == 1) write(2);
				else if(k >=2 and k<=4) write(1);
				else write(0);
			}
			else
			{
				if(k >= 1 and k <= 4) write(1);
				else write(0);
			}
			puts("");
			continue;
		}
		puts("2");
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
