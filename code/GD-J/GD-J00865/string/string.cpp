#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
char c[N],c2[N];
long long a[N],a2[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i] >> c[i];
		a2[n - i + 1] = a[i];
		c2[n - i + 1] = c[i];
	}
	long long pos = 0,pos2 = 0,p = 1,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		pos += a[i];
		while(pos2 + a2[p] <= pos && p <= n)
		{
			if(c2[p] != c[i]) ans += a2[p];
			pos2 += a2[p];
			p++;
		}
		if(pos2 != pos && p <= n)
		{
			if(c2[p] != c[i]) ans += pos - pos2;
			a2[p] -= pos - pos2;
			pos2 = pos;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
