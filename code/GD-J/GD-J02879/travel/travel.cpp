#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]+s1[1]!=s2[0]+s2[1]){
		cout<<1000;
		return 0;
	}
	if(s1[2]=='C'||s2[2]=='C'){
		if(s1[2]>'C'||s2[2]>'C'){
		
			cout<<1100;
			return 0;
		}
	}
	
	if(s1[2]-1>='C'-1&&s2[2]-1>='C'-1){
		cout<<1111;
		return 0;
	}else{
		if(s1[2]-1==s2[2]||s2[2]-1==s1[2]){
			cout<<1111;
			return 0;
		}else{
			cout<<1110;
			return 0;
		}
	}
	
	return 0;
} 
