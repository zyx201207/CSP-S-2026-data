#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

vector<char> s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	
	ll a,sum = 0;
	char c;
	for(ll i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for(ll j = 1; j <= a; j++)
		{
			s.push_back(c);
		}
		sum += a;
	}
	
	ll ans=0;
	for(ll i = 0; i < sum/2; i++)
	{
		if(s[i] != s[sum - 1 - i]) ans++;
	}
	cout << ans;
	
	return 0;
}
