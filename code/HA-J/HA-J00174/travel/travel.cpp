#include<bits/stdc++.h>
using namespace std;
char s[2],s2[2];
int c,q,c2,q2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c;
	int a=c;
	cin>>q>>s[2]>>c2>>q2>>s2[2];
	
	if(a!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	if(q==q2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s[2]<='C'&&s2[2]<='C')||(s[2]>='D'&&s2[2]>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	
	
	if((s[2]=='A'&&s2[2]=='B')||(s[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s[2]=='C'&&s2[2]=='B')||(s[2]=='D'&&s2[2]=='F')||(s[2]=='F'&&s2[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
