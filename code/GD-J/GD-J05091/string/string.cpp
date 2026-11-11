#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
char b;
string s = "";
string s1;
ll cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		while(a--)
		{
			s += b;
		}
	}
	s1 = s;
	reverse(s1.begin(),s1.end());
	for(ll i = 0;i < s.size() / 2;i++)
	{
		if(s1[i] != s[i]) cnt++;
	}
	cout << cnt;
	return 0;
} 

