#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+="1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(c1==c2 && s1[1]==s2[1]){
		ans+="1";
	}else{
		cout<<"1000";
		return 0;
	}
	if(c1==c2 && s1[1]==s2[1] && (s1[2]<='C' && s2[2]<='C' || s1[2]>='D' && s2[2]>='D')){
		ans+="1";
	}else{
		cout<<"1100";
		return 0;
	}
	if(c1==c2 && s1[1]==s2[1] && (s1[2]<='C' && s2[2]<='C' || s1[2]>='D' && s2[2]>='D')){
		if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1 || (s1[2]>='D' && s2[2]>='D' && s1[2]-s2[2]==2 || s1[2]-s2[2]==-2)){
			ans+="1";
		}else{
			cout<<"1110";
			return 0;
		}
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<ans;
	
	
	
	return 0;
} 
