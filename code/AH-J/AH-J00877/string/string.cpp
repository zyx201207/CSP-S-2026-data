#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
long long a[N];
char c[N];
bool hw(string a)
{
	string b=a;
	reverse(a.begin(),a.end());
	return b==a;
}
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	string t="";
	for(int i=1;i<=n;i++)
	{
		for(ll j=1;j<=a[i];j++)
		{
			t+=c[i];
		}
	}
	if(hw(t))
	{
		cout<<'0';
		return 0;
	}
	ll len=t.size();
	ll mid=len/2;
	ll cnt=0;
	for(ll i=0;i<=mid;i++)
	{
		if(t[i]!=t[len-i-1])
		{
			cnt++;
			t[len-i-1]=t[i];
		}
	}
	cout<<cnt;
	return 0;
}
