#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,s="0000";
int f(char a,char b){
	if(a>b){
		char t=b;
		b=a;
		a=t;
	}
	if(a=='A'&&b=='B')return 1;
	if(a=='B'&&b=='C')return 1;
	if(a=='D'&&b=='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		s[0]='1';
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			s[1]='1';
			char a=c1[2],b=c2[2];
			if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
				s[2]='1';
				if(f(a,b))s[3]='1';
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
