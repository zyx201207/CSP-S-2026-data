#include <iostream>

using std::cin;
using std::cout;

long long n;

long long a[100005];

char ch[100005];

long long ans = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> ch[i];
	}

	long long l = 1, r = n;

	while(l < r)
	{
		long long minus = std::min(a[l], a[r]);

		if(ch[l] != ch[r])
		{
			ans += minus;
		}

		a[l] -= minus;
		a[r] -= minus;

		if(a[l] == 0)
		{
			l++;
		}

		if(a[r] == 0)
		{
			r--;
		}
	}

	cout << ans;
}
