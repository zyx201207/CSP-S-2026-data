#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,a,ans,k;
char ch;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a>>ch;
		for(ll j=1;j<=a;j++)s+=ch;
	}
	k=s.size();
	for(ll i=0;i<=k/2-1;i++)
		if(s[i]!=s[k-i-1])ans++;
	cout<<ans;
	return 0;
}
