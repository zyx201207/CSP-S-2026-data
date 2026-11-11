#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	
	string c1;
	string s1;
	string c2;
	string s2;
	string a[4];
	cin >> c1 >> s1 >> c2 >> s2;
	
	//cin >> c2;
	//if(s1[0]=='1')cout << "10";
	if(c1==c2){a[0]='1';}
	else{a[0]="0";}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){a[1]='1';}
	else{a[1]="0";}

	if(a[1]=="1"){
		if((s1[2]>='A' && s1[2]<='C')&&(s2[2]>='A' && s2[2]<='C')){a[2]='1';}
		else if(('D'==s1[2]||s1[2]=='E')&&('D'==s2[2]||s2[2]=='E')){a[2]='1';a[3]='1';}
		else {a[2]='0';}
	}
	
	if(a[3] == "1"){cout << a;}
	
	if(abs(s1[2]-s2[2])==1){a[3]='1';}
	else {a[3]="0";}
	for(int i=0;i<4;i++){
		cout << a[i];
	}
	return 0;
}
