#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll n,a[200010],c;
char t;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>t;
		while(a[i]--)
		{
			s+=t;
		}
	}
	ll m=s.size();
	ll j=m-1;
	for(ll i=0;i<m;i++)
	{
		if(i==j)
		{
			break;
		}
		if(s[i]!=s[j])
		{
			c++;
		}
		j--;
	}
	cout<<c;
	return 0;
}
