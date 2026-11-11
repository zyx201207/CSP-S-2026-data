#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,w=0;
	string s;
	cin >>n;
	for(ll i=0;i<n;i++)
	{
		ll a;
		string b;
		cin >> a >> b;
		for(ll j=0;j<a;j++) s+=b;
	}
	ll k=s.size()/2;
	for(ll i=0,j=s.size()-1;i<k;i++,j--)
	{
		if(s[i]!=s[j]) 
		{
			w++;
		}
	}
	cout << w;
	return 0;
}
