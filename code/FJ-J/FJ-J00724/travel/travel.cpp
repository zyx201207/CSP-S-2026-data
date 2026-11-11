#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","a",stdout); 
	string c1,c2,s1,s2,m;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		m+="1";
	}else{
		m+="0000";
		cout<<m;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		m+="1";
	}else{
		m+="000";
		cout<<m;
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
		m+="1";
	}else{
		m+="00";
		cout<<m;
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		m+="1";
	}else{
		m+="0";
	}
	cout<<m;
	
	return 0;
}
