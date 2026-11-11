#include <bits/stdc++.h>
using namespace std;

long long a1_[200500], a2_[200500];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		long long kk;
		char c;
		cin >> kk >> c;
		a1_[i] = kk;
		a2_[i] = c - 'a';
	}
	long long la = n, fr = 1;
	while (fr <= la)
	{
		//cout << fr << " " << la << '\n';
		if (a2_[fr] != a2_[la])
		{
			if (a1_[fr] > a1_[la])
			{
				a1_[fr] -= a1_[la];
				ans += a1_[la];
				la--;
			}
			else if (a1_[fr] == a1_[la])
			{
				ans += a1_[fr];
				la--;
				fr++;	
			}
			else
			{
				a1_[la] -= a1_[fr];
				ans += a1_[fr];
				fr++;
			}
		}
		if (a2_[fr] == a2_[la])
		{
			if (a1_[fr] > a1_[la])
			{
				a1_[fr] -= a1_[la];
				la--;
			}
			else if (a1_[fr] == a1_[la])
			{
				la--;
				fr++;
			}
			else
			{
				a1_[la] -= a1_[fr];
				fr++;
			}
		}		
	}
	cout << ans << '\n';
	return 0;
} 
