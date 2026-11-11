#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("tavel.in","r",stdin);
	freopen("tavel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1[2]>'C'&&c2[2]<='C'||c2[2]>'C'&&c1[2]<='C'){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	if(c1[2]-1==c2[2]||c2[2]-1==c1[2]){
	
		cout<<"1";                           
	}
	else{
		cout<<"0";
	}          
	
    return 0;
}