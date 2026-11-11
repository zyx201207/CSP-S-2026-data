#include<bits/stdc++.h>
using namespace std;
string r1,r2,s1,s2;
int main(){
	cin>>r1>>r2>>s1>>s2;
	if(r1==s1){
		cout<<"1";	
	}
	if(r2[2]==s2[2]){
		cout<<"1";
		if(r2[3]=='A' || r2[3]=='B' || s2[3]=='C' && s2[3]=='A' || s2[3]=='B' || s2[3]=='C'){
			cout<<"1";
			}
		}
	return 0;
} 
