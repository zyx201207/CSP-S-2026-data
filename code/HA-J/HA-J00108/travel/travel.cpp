#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1;
	string s1;
	string c2;
	string s2;
	string a1=0,a2=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		
		if(s2!=s1){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
		}
		
	for(int i=1;i<=18;i++){
	if(s1==i+"D"||s1==i+"F"){
		a1=s1;
	if(s2==i+"D"||s2==i+"F"){
		a2=s2;
	}	
	}
}
	if(a1==s1&&a2==s2){
	cout<<"1";
	}else if(a1!=s1){
		if(a2==s2){
		cout<<"00";
		return 0;
			}
	}else{
		cout<<"1";
	}

		if(s2>s1){
			cout<<"1";
			
		}else{
			cout<<"0";
			return 0;
		}
	}else{
		cout<<"0000";
	return 0;
	}
return 0;
}
