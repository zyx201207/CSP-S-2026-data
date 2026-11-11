#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s[4];
	for(int i=0;i<4;i++){
		s[i]='0';
	}
	
	if(c1==c2){
		s[0]='1';
		if(s1.substr(0,2)==s2.substr(0,2)){
			s[1]='1';
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					s[2]='1';
					if(abs(s1[2]-s2[2])==1){
					s[3]='1';
					}
				}
			}else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					s[2]='1';
					if(abs(s1[2]-s2[2])==2){
						s[3]='1';
					}
				}
			}	
		}
	}
	for(int i=0;i<4;i++){
		cout<<s[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
