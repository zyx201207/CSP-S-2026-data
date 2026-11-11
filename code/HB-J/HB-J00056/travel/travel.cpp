#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[1]!=s2[1]||s1[2]!=s2[2]){
		cout<<"1000";
		return 0;
	}
	if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C'){
		if(!(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')){
			cout<<"1100";
			return 0;
		}
	}
	if(s1[3]=='D'||s1[3]=='F'){
		if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
			cout<<"1100";
			return 0;
		}
	}
	if(s1[3]=='A'){
		if(s2[3]!='B'){
			cout<<"1110";
			return 0;
		}
	}
	if(s1[3]=='B'){
		if(s2[3]!='A'&&s2[3]!='C'){
			cout<<"1110";
			return 0;
		}
	}
	if(s1[3]=='C'){
		if(s2[3]!='B'){
			cout<<"1110";
			return 0;
		}
	}
	if(s1[3]=='D'){
		if(s2[3]!='F'){
			cout<<"1110";
			return 0;
		}
	}
	if(s1[3]=='F'){
		if(s2[3]!='D'){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
}
