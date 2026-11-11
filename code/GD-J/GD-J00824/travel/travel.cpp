#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int fl=1;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]) fl=0;
	}
	if(fl){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	fl=0;
	if(s1[2]<='C'&&s2[2]<='C'){
		cout<<"1";
		fl=1;
	}
	if(fl){
		if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		if(s1[2]>'C'&&s2[2]>'C'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
