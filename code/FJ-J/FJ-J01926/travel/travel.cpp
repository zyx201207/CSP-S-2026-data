#include <bits/stdc++.h>
using namespace std;
int f(char x){
	if(x=='A' || x=='B' || x=='C'){
		return 1;
    }else{
    	return 0;
    }
}
bool g(string s1,string s2){
	int g1=s1[0]-'0'+(s1[1]-'0')*10;
	int g2=s2[0]-'0'+(s2[1]-'0')*10;
	if((g1==g2 && f(s1[2])==f(s2[2]) && max(s1[2]-'0',s2[2]-'0')-min(s1[2]-'0',s2[2]-'0')==1) || (max(g1,g2)-min(g1,g2)==1 && s1[2]==s2[2])){
		return true;
    }
    return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string u="";
	if(c1==c2){
		u+='1';
    }else{
    	u+='0';
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]){
    	u+='1';
	}else{
		u+='0';
    }
    if(s1[0]==s2[0] && s1[1]==s2[1] && f(s1[2])==f(s2[2])){
    	u+='1';
	}else{
		u+='0';
    }
    if(g(s1,s2)){
    	u+='1';
    }else{
    	u+='0';
    }
    cout<<u;
	return 0;
}
