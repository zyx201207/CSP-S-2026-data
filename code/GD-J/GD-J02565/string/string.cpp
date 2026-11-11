#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
string s,s2;
ll n,ans;
ll a[N];
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(ll j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	ll l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r]) ans++;
		l+=1;
		r-=1;
	}
	cout<<ans;
	return 0;
}


