#include<bits/stdc++.h>
using namespace std;

int main () {

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1=s1.substr(0,2),p2=s2.substr(0,2); // ее
	char ce1=s1[2],ce2=s2[2];
	int f1,f2,f3,f4;
	f1=f2=f3=f4=false;
	if(c1==c2) {
		f1=true;

	}
	if(f1&&p1==p2) {
		f2=true;
	}
	if(f1&&f2&&(ce1>='A'&&ce1<='C'&&ce2>='A'&&ce2<='C') || (ce1>='D'&&ce1<='F'&&ce2>='D'&&ce2<='F')) {
		f3=true;

	}
	if(f1&&f2&&f3&&(abs(int(ce1-ce2)))==1) {
		f4=true;
	}
	cout<<f1<<f2<<f3<<f4;




	return 0;
}
