#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int maxn=200005;
ll a[maxn];
bool f=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		string c;
		cin>>c;
		for(int j=0;j<a[i];j++)
		{
			s+=c;
		}
	}
	string s1;
	for(int i=s.length();i>0;i--)
	{
		s1+=s[i];
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=s1[i])
		{
			f=1;
		}
	}
	if(f==1)
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
}
