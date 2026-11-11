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

int n, m;
int a[500010];
int b[500010];
int f[500010];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(), m = read();
	for(int i = 1;i <= n;++i) a[i] = read();
	sort(a+1,a+1+n);
	for(int i = 1;i < n;++i)
	{
		b[i] = a[i+1] - a[i], f[i] = f[i-1] + b[i];
//		cout << a[i] << ' ';
	}
//	puts("");
	int ans = 0;
	int s = 0;
	int i = 1;
	for(int j = 1;j < n;++j)
	{
		s += (j-i+1) * b[j];
		while(s > m && i <= j)
		{
			s -= f[j] - f[i-1];
			++i;
		}
		ans = max(ans,j-i+2);
//		cout << i << ' ' << j << ' ' << s << endl;
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
