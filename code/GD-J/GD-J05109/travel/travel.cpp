#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_one,c_two,s_one,s_two;
	cin>>c_one>>s_one>>c_two>>s_two;
	bool s_o=false,s_t=false;
	int A='A',B=s_one[2],C=s_two[2];
	
	for(int i=0;i<3;i++){
		if(B==A)s_o=true;
		if(C==A)s_t=true;
		A++;
	}
	
	if(c_one==c_two)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s_one[0]==s_two[0]and s_one[1]==s_two[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	if(s_o==s_t)cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	
	if(s_one[2]+1==s_two[2]or s_one[2]-1==s_two[2])cout<<"1";
	else{cout<<"0";}
	
	return 0;
} 
