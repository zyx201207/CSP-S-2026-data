#include<bits/stdc++.h>
using namespace std;
string a1,b1,c1,a2,b2,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	a1=s1.substr(0,2),a2=s2.substr(0,2);
	b1=s1.substr(2,1),b2=s2.substr(2,1);
	if(a1==a2&&c1==c2)cout<<1;
	else cout<<0;
	if(b1<="C"&&b2<="C"&&a1==a2&&c1==c2)cout<<1;
	else if(b1>="E"&&b2>="E"&&a1==a2&&c1==c2)cout<<1;
	else cout<<0;
	if(b1<="C"&&b2<="C"&&a1==a2&&c1==c2&&!((b1=="A"&&b2=="C")||(b1=="C"&&b2=="A")))cout<<1;
	else if(b1>="E"&&b2>="E"&&a1==a2&&c1==c2&&b1!=b2)cout<<1;
	else cout<<0;
	return 0;
}

