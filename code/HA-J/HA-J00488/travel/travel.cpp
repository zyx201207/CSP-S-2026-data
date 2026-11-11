#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define cin fin
#define cout fout
ifstream fin("travel.in");
ofstream fout("travel.out");
int main(){
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool falg=false;
	string s="";
	if(c1==c2){
		falg=true;
		s+='1';
	}else{
		falg=false;
		s+='0';
	}
	
	bool falg2=false;
	if(falg){
		string s11;
		s11+=s1[0];
		s11+=s1[1];
		string s22;
		s22+=s2[0];
		s22+=s2[1];
		if(s11==s22){
			falg2=true;
			s+='1';
		}else{
			s+='0';
			falg2=false;
		}
	}else{
		falg2=false;
		s+='0';	
	}
	
	bool falg3=false;
	if(falg2){
		if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='E' && s2[2]>='D' && s2[2]<='E')){
			falg3=true;
			s+='1';
		}else{
			falg3=false;
			s+='0';
		}
	}else{
		falg3=false;
		s+='0';	
	}
	
	if(falg3){
		if(s1[2]=='A' && s2[2]=='B') s+='1';
		else if(s1[2]=='B' && s2[2]=='C') s+='1';
		else if(s2[2]=='A' && s1[2]=='B') s+='1';
		else if(s2[2]=='B' && s2[2]=='C') s+='1';
		else s+='0';
	}else{
		s+='0';	
	}
	
	cout << s;
	return 0;
}
