#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	string a,b,c,d,s="";
	cin>>a>>b>>c>>d;
	if(a==c){
		s+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			s+='1';
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
				s+='1';
				if((b[2]=='A'&&d[2]=='C')||(d[2]=='A'&&b[2]=='C')){
					s+='0';
				}
				else{
					s+='1';
				}
			}
			else if((b[2]=='C'||b[2]=='D')&&(d[2]=='C'||d[2]=='D')){
				s+='11';
			}
			else{
				s+='00';
			}
		}
		else{
			s+='000';
		}
	}
	else{
		s='0000';
	}
	cout<<s;
	freclose("r","travel.in",stdin);
	freclose("w","travel.out",stdout);
}
