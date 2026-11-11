#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100;
int main(){
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			if(s1[2]<='C'&&s1[2]<='C'||s1[2]>='D'&&s1[2]>='D'){
				if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
