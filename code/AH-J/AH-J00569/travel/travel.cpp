#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)) cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		if(s1[2]<='C'&&s2[2]<='C'&&s1!=s2) cout<<1;
		else if(s1[2]>'C'&&s2[2]>'C'&&s1!=s2) cout<<1;
		else cout<<0;
	}else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		if(s1[2]<='C'&&s2[2]<='C'&&abs(ll(s1[2])-ll(s2[2]))==1) cout<<1;
		else if(s1[2]>'C'&&s2[2]>'C'&&s1!=s2) cout<<1;
		else cout<<0;
	}else cout<<0;
	
	return 0;
}
