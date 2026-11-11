#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1(char x1,char x2){
	if(x1<='C'&&x2<='C') return true;
	else if(x1>'C'&&x2>'C') return true;
	else return false;
}
bool check2(char x1,char x2){
	if(x1>x2) swap(x1,x2);
	if(x1=='A'&&x2=='B') return true;
	if(x1=='B'&&x2=='C') return true;
	if(x1=='D'&&x2=='E') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << "1";
	else cout << "0";
	string q1="";
	q1+=s1[0];
	q1+=s1[1];
	char x1=s1[2];
	string q2="";
	q2+=s2[0];
	q2+=s2[1];
	char x2=s2[2];
	if(q1==q2&&c1==c2) cout << "1";
	else cout << "0";
	if(c1==c2&&q1==q2&&check1(x1,x2)) cout << "1";
	else cout << "0";
	if(q1==q2&&c1==c2&&check1(x1,x2)&&check2(x1,x2)) cout << "1";
	else cout << "0";
	return 0;
}
