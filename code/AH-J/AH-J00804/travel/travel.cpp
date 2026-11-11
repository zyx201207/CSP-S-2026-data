#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x != y) cout<<0;
	else cout<<1;
	
	ll s1 = (a[0] - '0') * 10 + (a[1] - '0');
	ll s2 = (b[0] - '0') * 10 + (b[1] - '0');
	if(s1 == s2 && x == y) cout<<1;
	else cout<<0;
	
	bool f1 = 0,f2 = 0;
	if(a[2] == 'A' || a[2] == 'B' || a[2] == 'C') f1 = 1;
	if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C') f2 = 1;
	if(f1 == f2 && s1 == s2 && x == y) cout<<1;
	else cout<<0;
	
	if((a[2] + 1 == b[2] || b[2] + 1 == a[2]) && f1 == f2 && s1 == s2 && x == y) cout<<1;
	else cout<<0;
	return 0;
}
