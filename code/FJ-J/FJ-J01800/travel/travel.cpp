#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b=1;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&(c1!="01"&&c1!="16")&&(c2!="01"&&c2!="16")){
		cout<<1;
		b++;	
	}
	else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&b==2){
		b++;
		cout<<1;	
	}
	else{
		cout<<0;
	}
	if(('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')&&b==3){
		b++;
		cout<<1;
	}
	else if(('D'==s1[2]||s1[2]=='E')&&('D'==s2[2]||s2[2]=='E')){
		cout<<1;
	}	
	else{
		cout<<0;
	}
	
	if(s1[2]=='D'){
		s1[2]++;
	}
	if(s2[2]=='D'){
		s2[2]++;
	}
	if(abs(s1[2]-s2[2])==1&&b==4){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
