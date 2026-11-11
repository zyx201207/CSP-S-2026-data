#include<iostream>
using namespace std;
int get(string s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C') return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	else if(c1.substr(0,2)!=c2.substr(0,2)){
		cout<<"1000";
	}
	else if(get(c1)!=get(c2)){
		cout<<"1100";
	}	
	else if(c1[2]-c2[2]!=1&&c2[2]-c1[2]!=1){
		cout<<"1110";
	}
	else cout<<"1111";
	return 0;
} 
