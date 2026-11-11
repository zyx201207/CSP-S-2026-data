#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s="1001";
	if(c1!=c2){
		cout<<"0000";
		return 0;	
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		s[1]=1;
		
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
			s[2]=1;
			if(s1[2]=='A'){
				if(s2[2]!='B')s[3]=0;; 
			}
			else if(s1[2]=='C'){
				if(s2[2]=='A') s[3]=0;
			}
		} 
		else if(s1[2]=='D'||s2[2]=='F'&&s2[2]=='D'||s2[2]=='F') s[2]=1;
		else s[3]=0;
	}
	else s[3]=0;
	for(int i=0;i<=3;i++)cout<<s[i];
	
	return 0;
}
