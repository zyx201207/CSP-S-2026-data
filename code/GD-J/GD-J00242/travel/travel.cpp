#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	a=(c1==c2);
	b=a&(s1.substr(0,2)==s2.substr(0,2));
	c=b&(s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C');
	d=c&(abs(s1[2]-s2[2])==1);
	cout<<a<<b<<c<<d;
	return 0;}
