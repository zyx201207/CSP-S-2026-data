#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int arr[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(m == 1)
	{
		int Max = INT_MIN;
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			Max = max(Max, arr[i]);
		}
		cout << Max << endl;
		return 0;
	}
	if(m == 2)
	{
		int Max = INT_MIN;
		for(int i = 1; i <= n; i++)
			cin >> arr[i];
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				Max = max(Max, (arr[i] & arr[j]));
		cout << Max << endl;
		return 0;
	}
	if(m == n)
	{
		int ans;
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			if(i == 1)
				ans = arr[i];
			else
				ans &= arr[i];
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
