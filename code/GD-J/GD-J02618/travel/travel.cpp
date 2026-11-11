#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n1=(c1[0]-'0')*10+(c1[1]-'0');
	int n2=(c2[0]-'0')*10+(c2[1]-'0');
	if(n1==n2){
		s+='1';
		int t1=(s1[0]-'0')*10+(s1[1]-'0');
		int t2=(s2[0]-'0')*10+(s2[1]-'0');
		if(t1==t2){
			s+='1';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				s+='1';
				if(s1[2]=='B'||s2[2]=='B'||s1[2]=='D'){
					s+='1';
				}
				else{
					s="1110";
				}
			}
			else{
				s="1100";
			}
		}
		else{
			s="1000";
		}
	}
	else{
		s="0000";
	}
	cout<<s;
	return 0;
} 
