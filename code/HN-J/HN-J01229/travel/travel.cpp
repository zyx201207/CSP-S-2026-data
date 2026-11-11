#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0; 
	}
	int s1_x,s2_x;
	s1_x=(s1[0]-'0')*10+(s1[1]-'0');
	s2_x=(s2[0]-'0')*10+(s2[1]-'0');
	if(s1_x==s2_x){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	bool d=false;
	if(((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C')) || ((s1[2]>='D' && s1[2]<='F') && (s2[2]>='D' && s2[2]<='F')) && s1[2]!=s2[2]){
		d=true;
	}
	if(s1_x==s2_x && d==true){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	int s1_y=s1[2]-'0',s2_y=s2[2]-'0';
	if(abs(s1_y-s2_y)==1 && ((s1[2]!='C' && s2[2]!='D') && (s1[2]!='D' && s2[2]!='C'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	} 
	return 0;
}
