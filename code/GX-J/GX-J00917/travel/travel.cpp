#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	string c1,c2,s1,s2,S;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		S+='1';
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			S+='1';
		}else{
			S+='0';
		}
		if(s1[2]>='A' and s1[2]<='C'){
			if(s2[2]>='A' and s2[2]<='C'){
				S+='1';
			}else{
				S+='0';
			}
		}else if(s1[2]>='D' and s1[2]<='E'){
			if(s2[2]>='D' and s2[2]<='E'){
				S+='1';
			}else{
				S+='0';
			}
		}
		if(s1[2]=='A' and s2[2]=='B' or s1[2]=='B' and s2[2]=='C' or s1[2]=='B' and s2[2]=='A' or s1[2]=='C' and s2[2]=='B' or s1[2]=='D' and s2[2]=='E' or s1[2]=='E' and s2[2]=='D'){
		S+='1';
		}else{
			S+='0';
		}
	}else{
		S="0000";
	}
	cout<<S;
	
	return 0;
}
