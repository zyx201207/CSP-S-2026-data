#include<bits/stdc++.h>
using namespace std;
int main(){
    
    freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'){
		cout<<'1';
	}else{
		cout<<'0';
	}
	int r,x;
	r=s1[2]-'A';
	x=s2[2]-'A';
	if(x<=2&&r<=2||x>=3&&r>=3){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(x<=2&&r<=2&&abs(x-r)==1||x>=3&&r>=3){
		cout<<'1';
	}else{
		cout<<'0';
	}
}
