#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<1;
	else cout<<0;
	if(a==b&&a1[0]==b1[0]&&a1[1]==b1[1]) cout<<1;
	else cout<<0;
	if(a==b&&a1[0]==b1[0]&&a1[1]==b1[1]&&(!((a1[2]=='C'&&b1[2]=='D')||(a1[2]=='D'&&b1[2]=='C')))) cout<<1;
	else cout<<0;
	if(a==b&&a1[0]==b1[0]&&a1[1]==b1[1]&&(!((a1[2]=='C'&&b1[2]=='D')||(a1[2]=='D'&&b1[2]=='C')))&&abs((int)(a1[2]-b1[2]))==1) cout<<1;
	else cout<<0;
	return 0;
}
