#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a,b,c,d;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
	} else {
		cout<<"0000"<<endl;
		return 0;
	}
	a=s1.substr(0,2);
	b=s2.substr(0,2);
	if(a==b) {
		cout<<"1";
	} else {
		cout<<"000"<<endl;
		return 0;
	}
	c=s1.substr(2);
	d=s2.substr(2);
	if(((c=="A"||c=="B"||c=="C")&&(d=="A"||d=="B"||d=="C"))||((c=="D"||c=="F")&&(d=="D"||d=="F"))) {
		cout<<"1";
	} else {
		cout<<"00"<<endl;
		return 0;
	}
	if((c=="A"&&d=="B")||(c=="B"&&(d=="A"||d=="C"))||(c=="C"&&d=="B")||(c=="D"&&d=="F")||(c=="F"&&d=="D")) {
		cout<<"1"<<endl;
	} else {
		cout<<"0"<<endl;
		return 0;
	}
	return 0;
}
