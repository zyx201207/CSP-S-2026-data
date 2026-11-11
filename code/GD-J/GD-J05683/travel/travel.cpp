#include<bits/stdc++.h>
using namespace std;
int main(){
	fopen("travel.in",cin,in);
	fopen("travel.in",cout,out);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	if(a==d){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}if(s[0]+s[1]==f[0]+f[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if((s[2]<='C'&&f[2]<='C')||(s[2]>='D'&&f[2]>='d')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(s[2]<='C'){
		if(s[2]=='B'||f[2]=='B'){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else	cout<<1;
	
	
	return 0;
}
