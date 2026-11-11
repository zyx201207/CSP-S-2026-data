#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,num,cnt = 0;
char a;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i = 1;i<=n;i++)
	{
		cin>>num>>a;
		for(ll j = 1;j<=num;j++)
		{
			s+=a;
		}
	}
	ll l = 0,r = s.size()-1;
	while(l<=r)
	{
		if(s[l] != s[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
