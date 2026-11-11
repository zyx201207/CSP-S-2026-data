#include<bits/stdc++.h>
using namespace std;
int c1,c2,si1,si2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	si1=(s1[0]-'0')*10+(s1[1]-'0');
	si2=(s2[0]-'0')*10+(s2[1]-'0');
	if(si1==si2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='F'){
		s1[2]='E';
	}
	if(s2[2]=='F'){
		s2[2]='E';
	}
	if((s1[2]==s2[2]-1&&s2[2]!='D')||(s1[2]==s2[2]+1&&s1[2]!='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
