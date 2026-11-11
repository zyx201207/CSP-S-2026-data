//GZ-J00041 贵阳市第二实验中学 吴宇轩
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string c1,s1,c2,s2,a,b;
	cin >> c1 >> s1 >> c2 >> s2;
	a = s1[0]+s1[1];
	b = s2[0]+s2[1];
	
	if (c1 == c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if (c1==c2 && a==b){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if (c1==c2 && a==b && (s1[2]=='A'||s1[2]=='B'|| s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B' || s2[2]=='C')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if (c1==c2 && a==b && (s1[2]=='B'&&s2[2]=='A'||s[2]=='C')||(s1[2]=='B'&&s2[1]=='A'||s2[1]=='C')){
		cout << 1;
	}
	else if(c1==c2 && a==b && (s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		    cout << 1;
	}
	else{
		cout << 0;
	}
	
	return 0;
} 
