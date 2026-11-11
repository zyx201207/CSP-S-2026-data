#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		ll x;
		char a;
		scanf("%lld",&x);
		cin>>a;
		for(ll i=1;i<=x;i++) s += a;
	}
	ll i=0,j=ll(s.size())-1;
	while(i < j){
		if(s[i] != s[j]) ans ++;
		i ++,j --;
	}
	cout<<ans;
	return 0;
}
