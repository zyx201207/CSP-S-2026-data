#include<bits/stdc++.h>
using namespace std;
int a,b,ans=1;
string sa,sb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	if(a!=b) ans=0;
	cout<<ans;
	if(sa.substr(0,2)!=sb.substr(0,2)) ans=0;
	cout<<ans;
	if(sa[2]<'D'&&sb[2]>'C'||sa[2]>'C'&&sb[2]<'D') ans=0;
	cout<<ans;
	if(sa[2]=='A'&&sb[2]=='C'||sa[2]=='C'&&sb[2]=='A') ans=0;
	cout<<ans;
	return 0;
}
