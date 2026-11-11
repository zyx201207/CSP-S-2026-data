#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll n; 
ll need=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll a;
		char c;
		cin>>a>>c;
		for(ll i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(ll i=0;i<s.size();i++){
		if(s[i]!=s[n+1-i])
		{
			need++;
		}
	}
	cout<<need/2;
	return 0;
}
