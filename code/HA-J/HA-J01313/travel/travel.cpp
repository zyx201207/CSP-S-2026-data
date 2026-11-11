#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
string s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	for(int i=1;i<=4;i++){
		s[i]='0';
	}
	if(r1==x1){
		s[1]='1';
		if(r2[0]==x2[0] && r2[1]==x2[1]){
			s[2]='1';
			if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
				if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
				s[3]='1';
				if( ((x2[2]=='A'||x2[2]=='B')&& (r2[2]=='A'||r2[2]=='B')) || ((x2[2]=='C'||x2[2]=='B')&& (r2[2]=='C'||r2[2]=='B'))){  
					s[4]='1';
					}
				}
			}
			else if((r2[2]=='D'||r2[2]=='F')&&(x2[2]=='D'||x2[2]=='F')){
				s[3]='1';
				s[4]='1';
			}
		}
}
	cout<<s[1]<<s[2]<<s[3]<<s[4];
	return 0;
} 
