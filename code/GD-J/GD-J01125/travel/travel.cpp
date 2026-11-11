#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=1;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	} 
	if(f&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	} 
	if(f&&('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')){
		cout<<1; 
	} else if(s1[2]>'C'&&s2[2]>'C'){
		cout<<1<<1;
		return 0;
	}else{
		cout<<0;
		f=0;
	} 
	if(f&&s1[2]=='B'||s2[2]=='B'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
