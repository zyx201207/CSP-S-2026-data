#include<bits/stdc++.h>
using namespace std;
int n=1;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
		cin>>c1>>s1>>c2>>s2;
	
	
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<'1';
	}else{cout<<'0';n=2;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&n==1){
		cout<<'1';
	}else{cout<<'0';n=3;
	}
	
	if(s1[2]+s2[2]-'A'-'A'==1&&n==1){
		cout<<'1';n=5;
	}
	if(s1[2]+s2[2]-'A'-'A'==2&&n==1){
		cout<<'1';n=5;
	}
	if(s1[2]+s2[2]-'A'-'A'==3&&n==1){
		cout<<'1';n=5;
	}
	if(s1[2]+s2[2]-'A'-'A'==7&&n==1){
		cout<<'1';n=5;
	}
	if(n!=5){
		cout<<'0';n=5;
	}
	if(s1[3]+1==s2[3]&&n==5){
		cout<<'1';n=11;
	}
	if(s1[3]-1==s2[3]&&n==5){
		cout<<'1';n=11;
	}
	if(n!=11){cout<<'0';
	}
	
	return 0;
}
