#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2e6 + 9;

ll c,t;
ll n,d;
ll x[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(ll i = 1; i <= n; i++) cin>> x[i];
		
		ll t = x[1] + d,j = 1;
		while(x[j] <= t) j++;
		
		cout << n - j + 1 << endl;
	}
	
	return 0;
}

