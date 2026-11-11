#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s=" ";
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char b;
		cin>>x>>b;
		for(int j=1;j<=x;j++)s+=b;
	}
	ll ans=0;
	for(int i=1;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i])ans++;
	}
	cout<<ans;
	return 0;
}

