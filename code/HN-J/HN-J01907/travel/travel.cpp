#include <bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
string s1,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	p1=int(s1[0]-'0')*10+int(s1[1]-'0');
	p2=int(s2[0]-'0')*10+int(s2[1]-'0');
	a=s1[2]-'A';
	b=s2[2]-'A';
	if(c1==c2)cout << 1;
	else cout << 0;
	if(p1==p2 && c1==c2)cout << 1;
	else cout << 0;
	if(p1==p2 && c1==c2 && (a<=2 && b<=2) || (a>=3 && b>=3))cout << 1 ;
	else cout << 0;
	if(p1==p2 && c1==c2 && (a<=2 && b<=2) || (a>=3 && b>=3)){
		if(a-1==b || a+1==b)cout << 1;
		else cout << 0;
	}
	else cout << 0;
	
	return 0 ;
}
