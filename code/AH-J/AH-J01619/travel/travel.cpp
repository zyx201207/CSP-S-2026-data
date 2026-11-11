#include <bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c==c2) cout<<1;
	else cout<<0;
	if(c==c2 && s[0]==s2[0] && s[1]==s2[1]) cout<<1;
	else cout<<0;
	if(c==c2 && s[0]==s2[0] && s[1]==s2[1] && (s[2]>='D' && s2[2]>='D' || s[2]<='C' && s2[2]<='C')) cout<<1;
	else cout<<0;
	if(c==c2 && s[0]==s2[0] && s[1]==s2[1] && (s[2]>='D' && s2[2]>='D' || s[2]<='C' && s2[2]<='C') && abs(s[2]-s2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
