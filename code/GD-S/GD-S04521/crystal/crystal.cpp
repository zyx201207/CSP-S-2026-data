#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll n,m,a[N],cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n % 2 == 0)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == a[n / 2]) cnt++;
		}
		for(int i = n / 2 - 1;i >= 1;i--)
		{
			while(a[i] < a[n / 2] && m)
			{
				a[i]++;
				m--;
			}
			if(a[i] == a[n / 2]) cnt++;
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == a[n / 2 + 1]) cnt++;
		}
		for(int i = n / 2;i >= 1;i--)
		{
			while(a[i] < a[n / 2 + 1] && m)
			{
				a[i]++;
				m--;
			}
			if(a[i] == a[n / 2 + 1]) cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
