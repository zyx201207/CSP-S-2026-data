#include <iostream>
using namespace std;

const int N = 2e5 + 5;
char C[N];
unsigned long long l = 1, r = 1, ans = 0, A[N], n;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int t;char c;
		scanf("%d %c", &t, &c);
		if (C[r - 1] == c) A[r - 1] += t;
		else
		{
			A[r] = t;C[r] = c;
			r++;
		}
	}
	while (l < r)
	{
		if (C[l] == C[r])
		{
			if (A[l] > A[r]) { A[l] -= A[r];r--; }
			else if (A[l] < A[r]) { A[r] -= A[l];l++; }
			else { l++;r--; } 
		}
		else
		{
			if (A[l] > A[r])
			{
				ans += A[r];
				A[l] -= A[r];
				r--;
			}
			else if (A[l] < A[r])
			{
				ans += A[l];
				A[r] -= A[l];
				l++;
			}
			else { ans += A[l];l++;r--; }
		}
	}
	cout << ans;
	return 0;
}
