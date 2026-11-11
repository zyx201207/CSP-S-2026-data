#include <iostream>
#include <vector>
using namespace std;
int n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	vector<long long> b(n + 1);
	vector<char> c(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i] >> c[i];
	}
	int w, a, s, d;
	w = 1, s = n;
	a = 1, d = b[n];
	long long cnt = 0;
	while (true)
	{
		if (w == s && a >= d)
			break;
		else if (w >= s)
			break;
		if (b[w] == b[s])
		{
			if (c[w] != c[s])
				cnt += b[w];
			b[w] = 0;
			b[s] = 0;
			w++;
			s--;
			a = 1;
			d = b[s];
			continue;
		}
		if (b[w] < b[s])
		{
			if (c[w] != c[s])
				cnt += b[w];
			d -= b[w];
			b[s] -= b[w];
			w++;
			a = 1;
			continue;
		}
		if (b[w] > b[s])
		{
			if (c[w] != c[s])
				cnt += b[s];
			a += b[s];
			b[w] -= b[s];
			s--;
			d = b[s];
			continue;
		}
	}
	cout << cnt;
}
