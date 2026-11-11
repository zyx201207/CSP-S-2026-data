#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s;
string st1,st2;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++)
		{
			s+=c;
		}
	}
	
	if(n%2==0)
	{
		for(int i=0;i<n/2+2;i++) st1+=s[i];
		for(int i=n/2+2;i<s.size();i++) st2+=s[i];
	}
	else
	{
		for(int i=0;i<n/2+1;i++) st1+=s[i];
		for(int i=n/2+2;i<s.size();i++) st2+=s[i];
	}
	ll i=0,cnt1=0,cnt2=0;
	while(i!=n-1)
	{
		if(st1[i]!=st2[i])
		{
			cnt1++;
		}
		i++;
	}
	i=0;
	while(i!=n-1)
	{
		if(st2[i]!=st1[i])
		{
			cnt2++;
		}
		i++;
	}
	cout<<min(cnt1,cnt2);
	return 0;
}
/*
3 
2 a
2 b
2 c
*/
