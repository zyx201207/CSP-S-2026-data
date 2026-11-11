#include<bits/stdc++.h>
using namespace std;
long long n, m, arr[200005], xx;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> arr[i];
	}
	
	sort(arr + 1, arr + 1 + n);
	for(int i = n;i > n - m;i--)
	{
		xx = arr[n];
		xx = xx & arr[i];
	}
	cout << xx;
}
