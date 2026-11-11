#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)a = 1;
	if(s1[0]==s2[0]&&s1[1]==s2[1])b = 1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				c = 1;
			}
		}else{
			if(s2[2]=='D'||s2[2]=='E'){
				c = 1;
			}
		}
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				char l = s1[2];
				if((char)(l-1)==s2[2]||(char)(l+1)==s2[2]){
					d = 1;
				}
			}
		}else{
			if(s2[2]=='D'||s2[2]=='E'){
				char r = s1[2];
				if((char)(r-1)==s2[2]||(char)(r+1)==s2[2]){
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
