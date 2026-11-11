#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}else{
		if(a2[0]!=b2[0]||a2[1]!=b2[1]){
			cout<<"1000"; 
			return 0;
		}
	} 
	char n=a2[2]; 
	char m=b2[2]; 
	if(abs((n-'0')-(m-'0'))==1){
		if(n=='A'||n=='B'||n=='C'&&m!='D'&&m!='E'){
			cout<<"1111";
			return 0;
		}else if(m=='A'||m=='B'||m=='C'&&n!='D'&&n!='E'){
			cout<<"1111";
			return 0;
		}else if(n=='E'&&m=='D'){
			cout<<"1111";
			return 0;
		}
		else if(n=='D'&&m=='E'){
			cout<<"1111";
			return 0;
		}
	}else{
		if(n=='A'||n=='B'||n=='C'&&m!='D'&&m!='E'){
			cout<<"1110";
			return 0;
		}else if(m=='A'||m=='B'||m=='C'&&n!='D'&&n!='E'){
			cout<<"1110";
			return 0;
		}
	} 
	cout<<"1100";
	return 0;
} 
