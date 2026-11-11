#include <bits/stdc++.h>
using namespace std;
struct s
{
	int a;
	char c;
}ac[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "0";
		return 0;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> ac[i].a >> ac[i].c;
	}
	long long l = 1,r = n,answer = 0;
	while (l <= r)
	{
		int w = min(ac[l].a,ac[r].a);
		if (ac[l].c != ac[r].c)
		{
			answer += w;
		}
		ac[l].a -= w;
		ac[r].a -= w;
		if (ac[l].a <= 0)
		{
			l++;
		}
		if (ac[r].a <= 0)
		{
			r--;
		}
	}
	cout << answer;
	return 0;
}
