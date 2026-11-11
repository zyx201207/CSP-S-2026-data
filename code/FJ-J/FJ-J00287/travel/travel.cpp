#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,x2;
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	fin>>c1>>s1>>c2>>s2;
	x1=int(s1[0]-'0')*10+int(s1[1]-'0');
	x2=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(c1!=c2){
	   fout<<"0000";
	   return 0;	
	}else{
		fout<<"1";
	}
	if(x1!=x2){
		fout<<"000";
		return 0;
	}else{
		fout<<"1";
	}
	if(s1[2]>'C'&&s2[2]>'C'){
		fout<<"11";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		fout<<"1";
		if(int(s1[2]-s2[2])*int(s1[2]-s2[2])==1){
			fout<<"1";
		}else{
			fout<<"0";
		}
	}else{
		fout<<"00";
	}
	
	
	return 0;
}