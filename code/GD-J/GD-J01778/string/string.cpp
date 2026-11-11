#include<bits/stdc++.h> 
using namespace std;
#define ll long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	string s="";
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		char c;
		cin>>c;
		for(ll j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	ll m=0;
	ll y=s.size(),x=y/2;
//	cout<<s<<endl; 
	for(ll i=0;i<x;i++)
	{
		if(s[i]!=s[y-i-1])
		{
			s[i]=s[y-i-1];
			m++;
//			cout<<"g s["<<i<<"] w "<<s[y-i-1]<<" "<<y-i-1<<endl;
		}
	}
//	cout<<s<<endl; 
	cout<<m;
	return 0;
}
//68,13~16和22~25过不了 
