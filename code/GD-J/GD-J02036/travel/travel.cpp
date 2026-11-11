#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
bool guo(string s1,string s2){
	return s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||((s1[2]>='E'&&s1[2]<='F')&&(s2[2]>='E'&&s2[2]<='F')));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(guo(s1,s2)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(guo(s1,s2)&&(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
