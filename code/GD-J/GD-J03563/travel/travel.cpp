#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,d1,d2;
	cin>>s1>>s2>>d1>>d2;
	if(s1==d1){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s2[0]==d2[0]&&s2[1]==d2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s2[0]==d2[0]&&s2[1]==d2[1]&&s2[2]<='C'&&d2[2]<='C'||s2[2]>'C'&&d2[2]>'C'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(int(s2[2])-1==int(d2[2])&&d2[2]<='C'&&s2[2]<='C'&&s2[0]==d2[0]&&s2[1]==d2[1]||s2[0]==d2[0]&&s2[1]==d2[1]&&s2[2]>'C'&&d2[2]>'C'||int(s2[2])+1==int(d2[2])&&d2[2]<='C'&&s2[2]<='C'||s2[2]>'C'&&d2[2]>'C'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
