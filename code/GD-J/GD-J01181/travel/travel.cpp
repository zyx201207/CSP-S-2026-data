#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string d1="ABDBCF",d2="BCFABD";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0; 
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]-'A'+1<=3 && s2[2]-'A'+1<=3) || (s1[2]-'A'+1>3 && s2[2]-'A'+1>3)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	for(int i=0;i<=5;i++){
		if(s1[2]==d1[i] && s2[2]==d2[i]){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
} 
