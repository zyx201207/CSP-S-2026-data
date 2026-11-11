#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
	}else{
		cout<<"1111"<<endl;
	}
	if(c1!=c2,s2==s1) {
		cout<<"1000"<<endl;
	}
	if(c1!=c2,c1=c2,s2==s1){
		cout<<"1110"<<endl;
	}
	return 0;
} 
