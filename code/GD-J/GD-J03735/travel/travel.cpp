#include<bits/stdc++.h>
using namespace std;
bool check1(string ss1,string ss2){
	if(ss1[2]>='A'&&ss1[2]<='C') return ss2[2]>='A'&&ss2[2]<='C';
	else return ss2[2]=='D'&&ss2[2]=='F';
}
bool check2(string ss1,string ss2){
	return (ss1[2]=='A'&&ss2[2]=='B')||(ss1[2]=='B'&&ss2[2]=='A')||(ss1[2]=='C'&&ss2[2]=='B')||(ss1[2]=='B'&&ss2[2]=='C')||(ss1[2]=='D'&&ss2[2]=='F')||(ss1[2]=='F'&&ss2[2]=='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << 1;
	else cout << 0;
	if(c1==c2 && (s1[0]==s2[0]&&s1[1]==s2[1])) cout << 1;
	else cout << 0;
	if(c1==c2 && (s1[0]==s2[0]&&s1[1]==s2[1]) && check1(s1,s2)) cout << 1;
	else cout << 0;
	if(c1==c2 && (s1[0]==s2[0]&&s1[1]==s2[1]) && check1(s1,s2) && check2(s1,s2)) cout << 1;
	else cout << 0;
	return 0;
}
