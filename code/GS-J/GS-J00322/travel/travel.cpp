#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a1>>b1>>c2>>a2>>b2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<1;
		if(a1!=a2)cout<<"000";
		else{
			cout<<1;
			cout<<((b1>='A'&&b1<='C'&&b2>='A'&&b2<='C')||(b1>='D'&&b1<='E'&&b2>='D'&&b2<='E'));
			cout<<((b1>='A'&&b1<='B'&&b2>='A'&&b2<='B')||(b1>='B'&&b1<='C'&&b2>='B'&&b2<='C')||(b1>='D'&&b1<='E'&&b2>='D'&&b2<='E'));
    	}
	}
	return 0;
}
