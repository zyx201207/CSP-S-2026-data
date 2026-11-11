#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200001],ans=0;
string s;
char c[200001];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(ll j=0;j<a[i];j++)
		{
			s+=c[i];
		}
	}
	for(ll i=0;i<(s.size()-1)/2;i++)
	{
		if(s[i]==s[s.size()-1-i])
		{
			continue;
		}
		else
		{
			s[s.size()-i]=s[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
