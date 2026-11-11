#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	string a1;a1+=c1[0];a1+=c1[1];
	string a2;a2+=c2[0];a2+=c2[1];
	if(a1!=a2){
		cout<<"1000";
		return 0;
	}
	char b1=c1[2];
	char b2=c2[2];
	if((b1<='C'&&b2>='D')||(b2<='C'&&b1>='D')){
		cout<<"1100";
		return 0;
	}
	if(abs(b1-b2)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
