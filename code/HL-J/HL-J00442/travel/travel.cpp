#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel1.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		cout<<"0000";
		return 0;
	}else if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
		cout<<1;
	}else{
		cout<<0;
	}
	int o=0;
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
		cout<<1;
		o=1;
	}else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='B')){
		cout<<1;
	}else{
		cout<<0;
	}
	if(o==1){
		cout<<1;
	}else if((s1[2]-'0'-1==s2[2]-'0'&&s1[2]-'0'-1!='C'-'0')||(s1[2]-'0'+1==s2[2]-'0'&&s1[2]-'0'+1!='D'-'0')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
