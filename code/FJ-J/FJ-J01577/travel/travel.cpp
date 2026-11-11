#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
using namespace std;
string a,s,b,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b)cout<<1;
	else cout<<0;
	string tmp;tmp.pb(s[0]),tmp.pb(s[1]);
	string tmp2;tmp2.pb(t[0]),tmp2.pb(t[1]);
	if(a==b&&tmp==tmp2)cout<<1;
	else cout<<0;
	if(a==b&&tmp==tmp2&&((s[2]<='C'&&t[2]<='C')||('C'<s[2]&&'C'<t[2])))cout<<1;
	else cout<<0;
	if(a==b&&tmp==tmp2&&((s[2]<='C'&&t[2]<='C')||('C'<s[2]&&'C'<t[2]))&&abs(s[2]-t[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
