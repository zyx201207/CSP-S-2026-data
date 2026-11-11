#include <bits/stdc++.h>
using namespace std;
//good luck
const int MAXN = 2 * 1e5 + 111;
int k; int n = 1; long long str [MAXN] [3]; long long ans;

void debug ()
{
	for (int i = 1; i <= n; ++ i)
		printf ("%lld %lld\n", str [i] [1], str [i] [2]);
	printf ("%lld\n", ans);
}

int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> k;
	for (int i = 1; i <= k; ++ i, ++ n)
	{
		char tmp;
		scanf ("%lld %c", &str [n] [1], &tmp);
		str [n] [2] = (int) tmp;
		if (str [n] [2] == str [n - 1] [2])
		{
			-- n;
			str [n] [1] += str [n + 1] [1];
		}
	}
	-- n;
	int j = n;
	for (int i = 1; i <= n; ++ i, -- j)
	{
		
		if (i >= j)
			break;
		if (str [i] [2] == str [j] [2])
		{
			if (str [i] [1] > str [j] [1])
			{
				str [i] [1] -= str [j] [1];
				str [j] [1] = -1;
				i --;
			}
			else
			{
				str [j] [1] -= str [i] [1];
				str [i] [1] = -1;
				j ++;
			}
		}
		else
		{
			long long tmp = min (str [i] [1], str [j] [1]);
			if (str [i] [1] > str [j] [1])
			{
				str [i] [1] -= str [j] [1];
				str [j] [1] = -1;
				i --;
			}
			else
			{
				str [j] [1] -= str [i] [1];
				str [i] [1] = -1;
				j ++;
			}
			ans += tmp;
		}
		
	//debug ();
	
	}
	printf ("%lld", ans);
}
