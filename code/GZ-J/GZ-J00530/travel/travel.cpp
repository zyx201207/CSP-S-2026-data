//GZ-J00530 Õ²»ÛÑş ºëÒãÖĞÑ§  
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
bool l(string s1,string s2){
	int i=0;
	if(s1[2]<='C'||s1[2]>='A') i++;
	if(s2[2]<='C'||s2[2]>='A') i++;
	if(s1[2]=='D'||s1[2]=='F') i++;
	if(s2[2]=='D'||s2[2]=='F') i++;
	if(i=2) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int g=0;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";g++;
	} 
	if(s1[0]=s2[0]&&s1[1]==s2[1]&&g==0){
		cout<<"1";
	}else {
		cout<<"0";g++;
	}
	if(l(s1,s2)&&g==0){
		cout<<"1";
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1) cout<<"1";
		else cout<<"0";
	}else cout<<"00";	
	return 0;
}
