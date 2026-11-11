#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int check=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0'){
		cout<<1; 
	}
	else{
		cout<<0;
	}
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0' && s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0' && s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'&&s1[2]-'A'<='C'-'A'&&s2[2]-'A'<='C'-'A'||s1[2]-'A'>'C'-'A'&&s2[2]-'A'>'C'-'A'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0' && s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'&&s1[2]-'0'==s2[2]-'0'+1||s1[2]-'0'==s2[2]-'0'-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
 
