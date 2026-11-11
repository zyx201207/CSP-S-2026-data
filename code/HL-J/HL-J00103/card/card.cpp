#include <bits/stdc++.h>

long long n,m;
typedef long long ll;
ll  a[1500000];
ll asw[1500000];
ll mstack[1500000];
ll msp;
using namespace std;
void game(ll gs)
{
	for (ll i = gs-1;i < n;i++)
	{
		bool hv = 0;
		for (ll j = 0;j < msp;j++)
		{
			if (mstack[j] == a[i])
			{
				msp = j;
				hv = 1;
				break;
			}
		}
		mstack[msp] = a[i];
		msp ++;
	}
	// cout << endl;
	for (ll i = 0;i < msp;i++)
	{
		asw[mstack[i]] ++;
		// cout << mstack[i] << " ";
	}
	// cout << endl;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	cin.tie(0);
	for (ll i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (ll i = 1;i <= n;i++)
	{
		game(i);
		msp = 0;
	}
	for (ll i = 1;i <= m;i++)
	{
		cout << asw[i] << " ";
	}
	return 0;

}
