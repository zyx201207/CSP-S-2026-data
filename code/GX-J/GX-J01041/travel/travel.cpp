#include <bits/stdc++.h>
using namespace;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<1;
	else cout<<0;
	if(c2==s2)cout<<1;
	else cout<<0;
	return 0;
}
