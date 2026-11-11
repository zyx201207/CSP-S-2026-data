#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define rep(i,a,n) for(ll i=a;i<=n;++i)
ll n;
string s;
ll check(string s)
{
	ll num=s.size()/2;//2
	ll c=s.size();//5
	ll cnt=0;
	for(ll i=0;i<num;i++)
	{
		if(s[i]!=s[c-1-i])cnt++;
	}
	return cnt;
}
void sol()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	rep(i,1,n)
	{
		ll a;
		cin>>a;
		string s1;
		cin>>s1;
		rep(i,1,a)s+=s1;
	}
	cout<<check(s)<<endl;
	
}
int main()
{
	sol();
	return 0;
}
