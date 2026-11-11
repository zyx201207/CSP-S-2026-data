#include<bits/stdc++.h>
using namespace std;
long long n, m, arr[200005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdin);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> arr[i];
	}
	for(int i = 1;i <= m;i++)
	{
		cout << n << ' ';
	}
}
