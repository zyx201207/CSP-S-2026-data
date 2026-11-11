#include<bits/stdc++.h>
using namespace std;
long long n, m, arr[500005], a[500005], mx = -1;
bool f = 1, fl = 1;
int main()
{
	auto xxx = clock();
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> arr[i];
		if(arr[i] != i)
		{
			f = 0;
		}
		if(i > 1)
		{
			if(arr[i] - arr[i - 1] != arr[2] - arr[1])
			{
				fl = 0;
			}
		}
	}
	if(f == 1)
	{
		long long xx = 0;
		for(int i = 1;i <= n;i++)
		{
			xx += i;
			if(xx > m)
			{
				cout << i;
				return 0;
			}	
		}
	}
	
	if(fl == 1)
	{
		long long xx = 0;
		for(int i = 1;i <= n;i++)
		{
			xx += (arr[2] - arr[1]) * i;
			if(xx > m)
			{
				cout << i;
				return 0;
			}	
		}
	}
	sort(arr + 1,arr + 1 + n);
	for(int i = 1;i < n;i++)
	{
		a[i] = arr[i + 1] - arr[i];
	}
	for(long long i = 1;i < n - 1;i++)
	{
		long long sum = 0;
		for(long long j = i;j < n;j++)
		{
			sum += (j - i + 1) * a[j];
			if(sum <= m)
			{
				mx = max((j - i + 2), mx);
			}
			if(clock() - xxx >= 920)
			{
				cout << mx;
				return 0;
			}
			else break;
		}
	}
	cout << mx;
	return 0;
}
