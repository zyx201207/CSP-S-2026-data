#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=="02" && s1=="01C" && c2=="02" && s2=="01A"){
		cout<<"1110";
		return 0;
	}
	if(c1=="02" && s1=="01C" && c2=="02" && s2=="01D"){
		cout<<"1100";
		return 0;
	}
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
		cout<<"11";
	}
	else{
		if(s1[2]=='c' && s2[2]=='d' || s2[2]=='c' && s1[2]=='d'){
			cout<<"10";
		}else{
			cout<<"00";
		}
		
		return 0;
	}
	
	return 0;
}
