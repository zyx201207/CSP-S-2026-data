#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int Rs,Xs;
bool as=0;
bool a(string s1,string s2){
	if(s1[0]==s2[0]&&s2[1]==s2[1]){
		return 1;
	}
	return 0;
}
bool b(string s1,string s2){
	if(abs(int(s1[2]-s2[2]))<=2){
		as=1;
		if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='F'))
		{
			as=0;
		}
	}
	return as;
}
bool c(string s1,string s2){
	bool acs=0;
	if(abs(int(s1[2]-s2[2]))==1&&as!=0){
		acs=1;
	}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='C')){
		acs=1;
	}
	return acs;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	cout<<a(s1,s2)<<b(s1,s2)<<c(s1,s2);
	return 0;
}
