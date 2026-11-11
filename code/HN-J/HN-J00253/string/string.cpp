#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e5+5;
ll n,len,cnt; string s="";

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		ll a; char ch;
		scanf("%lld",&a);
		cin>>ch;
		len+=a;
		while(a--) s+=ch;
	}
	
	for(int i=1;i<=len/2;i++)
	{
		if(s[i]!=s[len+1-i]) cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}
