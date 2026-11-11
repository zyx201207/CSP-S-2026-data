#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
ll n,ans;
string s;
void in() {
	cin>>n;
	ll len=1;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		char y;
		cin>>x>>y;
		while(x--)s+=y;
	}
	return ;
}
void work() {
//	cout<<s<<endl;
	for(ll i=0;i<s.size()/2;i++)
		if(s[i]!=s[ll(s.size())-i-1])ans++;//¿Ó 
	return ;
}
void out() {
//	cout<<s;
	cout<<ans<<endl;
	return ;
}
signed main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	in();
	work();
	out();
	return 0;
}

