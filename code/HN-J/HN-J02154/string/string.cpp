#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i <= n;i++)
	{
		ll sum;
		char c;
		cin >> sum >> c;
		for(ll j = 1;j <= sum;j++)
		{
			s += c;
			
		}
	}
	int flag = 1;
	for(int i = 1;i <= n;i++)
	{
		if(s[i] != s[i+1]) flag = false;
	}
	if(flag == true) 
	{
		cout << 0;
		return 0;
	}
	ll cnt = 0;
	ll len = s.size();
	ll i = 0;
	while(i <= len / 2)
	{
		if(s[i] != s[len-i]) cnt++;
		i++;
	}
	cout << cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
