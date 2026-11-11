#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	while(n--)
	{
		ll m;
		char a;
		cin>>m>>a;
		for(ll i = 0;i<m;i++)
		{
			s+=a;
		}
	}
	string sss;
	for(ll i = s.size()-1;i>=0;i--)
	{
		sss+=s[i];
	}
	if(sss==s)
	{
		cout<<0;
		return 0;
	}
	ll ans=0,r=1,l=1;
	string s_l;
	string s_r;
	ll ans_l=0;
	ll ans_r=0;
	ll size;
	size=s.size()/2;
	
	for(ll i = 0;i<s.size();i++)
	{
			if(i<size)
			{
				s_l+=s[i];
			}
			else if(i>=size)
			{
				if(s_l[s_l.size()-l]!=s[i])
				{
					ans_l++;
				}
				
				l++;
			}
	}
	if(s.size()%2==1)
		size++;
	for(ll i = s.size()-1;i>=0;i--)
	{
		
			if(i>=size)
			{
				s_r+=s[i];
			}
			else if(i<size)
			{
				if(s_r[s_r.size()-r]!=s[i])
				{
					ans_r++;
				}
				r++;
			}
	}
	ans=min(ans_r,ans_l);
	cout<<ans;
	return 0;
}
