#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string s="";
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	}
	string t1="",t2="";
	for(int i=0; i<2; i++) {
		t1+=s1[i];
		t2+=s2[i];
	}
	if(t1!=t2) {
		cout<<"1000";
		return 0;
	}
	char c1=s1[2],c2=s2[2];
	bool f=((c1>='A'&&c1<='C'&&c2>='A'&&c2<='C')||(c1>='D'&&c1<='F'&&c2>='D'&&c2<='F'));
	if(!f) {
		cout<<"1100";
		return 0;
	}
	if((abs(c1-c2)==1)||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')) cout<<"1111";
	else {
		cout<<"1110";
		return 0;
	}
	return 0;
}
//Ren Boda
