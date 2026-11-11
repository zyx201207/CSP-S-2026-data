#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
char c[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
	ll l = 0;
	ll ans = 0;
	for(ll i = 1;i <= n; i++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
	}
	ll j = n / 2;
	ll pd = 0;
	ll num = a[j];
	bool b = false;
	for(ll i = n / 2;i >= 1; i--)
	{
		//cout << c[j] << " " << c[n - j + 1] << endl;
		
		if(c[j] == c[n - j + 1])
		{
			num -= a[n-j + 1];
			b = true;
			if(num >= 0)
			{
				j -= 1;
			}
			else if(num < 0)
			{
				j = n - j + 1;
				num = abs(num);
			}
		}
		else
		{
			num -= a[n-j + 1];
			b = false;
			//cout << num << endl;
			ans += min(a[j],a[n - j + 1]);
			if(num >= 0)
			{
				j -= 1;
				if(i > 1 && num != 0)
				{
					num = a[j];
				}
				//cout << num << endl;
			}
			else if(num < 0)
			{
				j = n - j + 1;
				num = abs(num);
				
			}
		}
		//cout << ans <<" " << num << endl;
	}
	if(!b)
	{
		ans += num;
	}
	//cout << num << endl;
	cout << ans;
	return 0;
} 
