#include<bits/stdc++.h>
using namespace std;
string a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>aa>>bb;
	if(a!=aa){
		cout<<"0000";
		return 0;
	}
	if(b[1]!=bb[1]||b[0]!=bb[0]){
		cout<<"1000";
		return 0;
	}
	if((bb[2]=='D'&&b[2]!='F')||(b[2]=='D'&&bb[2]!='F')){
		cout<<"1100";
		return 0;
	}
	if((bb[2]=='A'&&b[2]=='C')||(b[2]=='A'&&bb[2]=='C')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
