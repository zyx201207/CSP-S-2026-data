#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	bool pai=true;
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout<<"1";
	}
	else{
		pai=false;
		cout<<"0";
	}
	bool ce=true;
	if(pai==true){
		if(s1[2] <= 'C'&&s2[2]<='C' || s1[2] > 'C' && s2[2] > 'C'){
			cout<<"1";
		}
		else{
			ce=false;
			cout<<"0";
		}
	}
	else{
		ce=false;
		cout<<"0";
	}
	if(ce==true){
		if((s1[2]-'A') - (s2[2] - 'A') == 1 || (s1[2]-'A') - (s2[2] - 'A') == -1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
