#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,ansmx = -1;
int a[N],sum[N];
//bool A = 1,B = 1;
inline int read()
{
	int k = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = k * 10 + c - '0';
		c = getchar();
	}
	return k*f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x < 10)
	{
		putchar(x + '0');
	}
	else
	{
		write(x / 10);
		putchar(x % 10 + '0');
	}
}
inline int chose(int pos)
{
	int ans = 1,jl = 0,mm = m;
	while(pos > 1)
	{
		jl += sum[pos];
		//cout << sum[pos] << endl;
		//cout << mm << " " << jl << endl;
		if (mm >= jl)
		{
			mm -= jl;
			ans++;
		}
		else
			break;
		//cout << mm << " " << jl << endl;
		pos--;
	}
	//cout << ans << endl << endl;;
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//cin >> n >> m;
	n = read(),m = read();
	for (int i = 1;i <= n;i++)
	{
		//cin >> a[i];
		//cout << a[i] << " ";
		/*if (a[i] != i)
			A = 0;*/
		a[i] = read();
	}
	//cout << endl;
	sort(a + 1,a + n + 1);
	for (int i = 2;i <= n;i++)
	{
		sum[i] = a[i] - a[i - 1];
		//cout << sum[i] << " ";
		/*if (sum[i] != sum[i - 1] && i > 2)
			B = 0;*/
	}
	/*if (A)
	{
		//cout << "A" << endl;
		int anns = 1,ges = 1;
		while (ges < m)
		{
			anns++;
			ges += ges;
		}
		cout << anns;
	}
	if (B)
	{
		//cout << "B" << endl;
		int anns = 1,ges = sum[2];
		while (ges < m)
		{
			anns++;
			ges += ges;
		}
		cout << anns;
		return 0;
	}
	//cout << endl;*/
	for (int i = 1;i <= n;i++)
	{
		ansmx = max(chose(i),ansmx);
		//cout << chose(i) << endl;
	}
	//cout << ansmx;
	write(ansmx);
	return 0;
}
