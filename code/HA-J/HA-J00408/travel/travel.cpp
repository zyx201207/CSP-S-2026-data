#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string a="";
	if(c1==c2){
		a+='1';
	}else{
		a+='0';
	}string b="",c="";
	for(int i=0;i<=1;i++){
		b+=s1[i];
		c+=s2[i];
	}if(b==c && c1==c2){
		a+='1';
	}else{
		a+='0';
	}if(b==c){
		if((s1[2]=='A' && (s2[2]=='B' || s2[2]=='C'))
		 || (s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) 
		 || (s1[2]=='C' && (s2[2]=='B' || s2[2]=='A')) || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
			a+='1';
		}else{
			a+='0';
		}
	}else{
		a+='0';
	}if(b==c){
		if((s1[2]=='A' && s2[2]=='B')
		 || (s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) 
		 || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
			a+='1';
		}else{
			a+='0';
		}
	}else{
		a+='0';
	}cout << a;
	return 0;
}
