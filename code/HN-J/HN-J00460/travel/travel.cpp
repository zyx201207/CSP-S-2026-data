#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen ("travel.in","w",stdin);
	freopen ("travel.out","r",stdout);
	string c[3],s1,s2;
	char a[6];
	for (int i=1;i<=1;i++){
		cin>>c[i]>>s1;
	    
	}
	for (int i=2;i<=2;i++){
		cin>>c[i]>>s2;
		
	}
	if (c[1]==c[2]){
		a[1]='1';
	}else {
		a[1]='0';
	}
	if (c[1]==c[2]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		a[2]='1';
	}else {
		a[2]='0';
	}
	if (c[1]==c[1]&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		a[3]='1';
		
	}else {
		a[3]='0';
		
	}
	if (s1[2]==s2[2]-1||s1[2]==s2[2]+1){
		a[4]='1';
	}else {
		a[4]='0';
	}
	for (int i=1;i<=4;i++){
		cout <<a[i];
	}
	
	return 0;
}
