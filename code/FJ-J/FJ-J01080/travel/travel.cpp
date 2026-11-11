#include <bits/stdc++.h>

using namespace std;

char c[5][5];
char s[5][5];
bool p = false;
char R,X;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c[1][1] >> c[1][2];
	cin >> s[1][1] >> s[1][2] >> s[1][3];
	cin >> c[2][1] >> c[2][2];
	cin >> s[2][1] >> s[2][2] >> s[2][3];
	if(s[1][3]=='F' || s[1][3]=='D') R = 's';
	else R = 'x';
	if(s[2][3]=='F' || s[2][3]=='D') X = 's';
	else X = 'x';
	
	if(c[1][2]==c[2][2]) cout << "1";
	else cout << "0";
	
	
	if(s[1][1]==s[2][1] && s[1][2]==s[2][2] && c[1][2]==c[2][2]){
		cout << "1";
		p = true;	
	}
	else cout << "0";
	
	if(p!=true){
		cout << "0";
	}
	else{
		if(R==X && c[1][2]==c[2][2]) cout << "1";
		else cout << "0";
	}
	
	if(s[1][3]+1==s[2][3] && R==X && p==true && c[1][2]==c[2][2]) cout << "1";
	else if(s[1][3]-1==s[2][3] && R==X && p==true && c[1][2]==c[2][2]) cout << "1";
	else cout << "0";
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
