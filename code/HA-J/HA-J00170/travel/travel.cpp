#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int b, r, x;
	
int main(){
	freopen("travel.in.in","r",stdin);
	freopen("travel.out.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') r=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') x=1;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout << 1;
		b=1;
	}
	else{
		cout<< 0;
		b=0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && b==1){
		cout<< 1;
		b=1;
	}
	else{
		cout << 0;
		b=0;
	}
	if(r==x && b==1){
		cout << 1;
		b=1;
	}
	else{
		cout << 0;
		b=0;
	}
	if((s1[2]==s2[2]+1||s2[2]==s1[2]+1) && b==1){
		cout << 1;
	}
	else cout << 0;
	return 0;
}
