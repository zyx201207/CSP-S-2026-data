#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	
	string s="";
	cin>>a>>b>>c>>d;
	if (a!=c){
		s.append(4,'0');
		cout<<s;
		return 0;
	}
	else{
		s.append(1,'1');
		if (b.substr(0,2) == d.substr(0,2)){
			s.append(1,'1');
			if (b[2]=='D' or b[2] == 'F'){
				if (d[2]=='D' or d[2]=='F'){
					s.append(1,'1');
				}else{
					s.append(1,'0');
				}
			}else{
				if (d[2]=='A' or d[2]=='B' or d[2]=='C'){
					s.append(1,'1');
				}else{
					s.append(1,'0');
				}
			}
		}else{
			s.append(2,'0');
		}
		int bn=(b[0]-'0')*10+(b[1]-'0');
		int dn=(d[0]-'0')*10+(d[1]-'0');
		if (abs(bn-dn)>1){
			s.append(1,'0');
			cout<<s;
		}else if (abs(bn-dn)==0){
			if (abs(b[2]-d[2])==1){
				if (b[2]=='C' and d[2]=='D' or b[2]=='D' and d[2]=='C'){
					s.append(1,'0');
					cout<<s;
				}else{
					s.append(1,'1');
					cout<<s;
				}
			}else{
				s.append(1,'0');
				cout<<s;
			}
		}else{
			if(b[2]==d[2]){
				s.append(1,'1');
					cout<<s;
			}else{
				s.append(1,'0');
					cout<<s;
			}
		}
			
	}
	return 0;
} 
