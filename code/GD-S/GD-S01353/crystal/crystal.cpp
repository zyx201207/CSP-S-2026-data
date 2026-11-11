#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll n,a[N],m,s[5001][5001],dif,ans = -0x3f;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
    cin>>n>>m;
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	memset(s, 0, sizeof(s));
	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i; j <= n; j++)
		{
			dif = a[j] - a[j - 1];
		    s[i][j] = s[i][j - 1] + (j - i) * dif;
		}
	}
	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i; j <=n; j++)
		{
			s[i][j] -= m;
		}
	}
	int tmp = 0;
	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i; j <= n; j++)
		{
			if(s[i][j] > 0)break;
			tmp++;
		}
		if(tmp > ans)ans = tmp;
		tmp = 0;
	}
	cout << ans;
	return 0;
} 

