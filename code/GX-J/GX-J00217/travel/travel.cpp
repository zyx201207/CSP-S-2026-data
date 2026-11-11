#include<bits/stdc++.h>
using namespace std;
int c1,c2,n=0,m=0;
string s1,s2,s="3333";
int main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A'){
		n=1;
	}else if(s1[2]=='B'){
		n=1;
	}else if(s1[2]=='C'){
		n=1;
	}
	if(s2[2]=='A'){
		m=1;
	}else if(s2[2]=='B'){
		m=1;
	}else if(s2[2]=='C'){
		m=1;
	}
	
	if(n==m){
		s[2]='1';
	}else{
		s[2]='0';
	}
	if(c1==c2){
		s[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			s[1]='1';
			if(n!=m){
				s[3]='0';
			}else{
				if(s1[2]=='D'){
					if(s2[2]=='F'){
						s[3]='1';
						cout<<s;
						return 0;
					}else{
						s[3]='0';
					}
				}else if(s1[2]=='F'){
					if(s2[2]=='D'){
						s[3]='1';
						cout<<s;
						return 0;
					}else{
						s[3]='0';
					}
				}
				if(s2[2]=='D'){
					s[3]='0';
					cout<<s;
					return 0;
				}else if(s2[2]=='F'){
					s[3]='0';
					cout<<s;
					return 0;
				}else{
					if(s1[2]=='B'){
						s[3]='1';
					}else if(s2[2]=='B'){
						s[3]='1';
					}else{
						s[3]='0';
					}
				}
			}
		}else{
			s[1]='0';
			s[2]='0';
			s[3]='0';
		}		
	}else{
		s="0000";
		cout<<s;
		return 0;
	}
	cout<<s;
	return 0;
}
