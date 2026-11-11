#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5;
ll n;
ll a[N];
string c;
string s="0";
ll l,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		ll j=a[i];
		l+=a[i];
		while(j--)
			s+=c;
	}
	for(int i=1;i<=l;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			cnt++;
			s[l+1-i]=s[i];
		}
	}
	cout<<cnt;
	return 0;
}
