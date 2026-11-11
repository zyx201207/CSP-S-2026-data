#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mk make_pair

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x*f;
}

int c, t;

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(), t = read();
	while(t--)
	{
		int n = read(), t = read();
		for(int i = 1;i <= n;++i) int u = read(), v = read();
		int m = (n-1)/2;
		printf("%lld\n",(m-(k/2))/2);
	}
	return 0;
}
