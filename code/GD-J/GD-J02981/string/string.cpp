#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll a[10000000];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll peak;
	string b[1000000];
	string k, f = "";
	int n;
	int sum = 0;
	cin >> n;
	int ans = 0;
	for(int i = 1; i<= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		cin >> k;
		for(int l = 1; l<= a[i]; l++)
		{
			f += k;
		}
	}
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if(sum % 2 == 0)
	{
		peak = sum / 2 - 1;
		for(int i = 0; i<= peak; i++)
		{
			if(f[i] != f[sum - i - 1])
			{
				ans += 1;
			}	
		}
	}
	else
	{
		peak = (sum + 1) / 2 - 1;
		for(int i = 0; i< peak; i++)
		{
			if(f[i] != f[sum - i -1])
			{
				ans += 1;
			}	
		}
	}
	cout << ans << endl;
	return 0;
}
