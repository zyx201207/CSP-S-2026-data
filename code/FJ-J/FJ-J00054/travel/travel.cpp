#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
inline bool check1(char x,char y){
	if(x=='A') return (y=='B' || y=='C');
	if(x=='B') return (y=='A' || y=='C');
	if(x=='C') return (y=='A' || y=='B');
	if(x=='D') return y=='F';
	if(x=='F') return y=='D';
}
inline bool check2(char x,char y){
	if(x=='A') return y=='B';
	if(x=='B') return (y=='A' || y=='C');
	if(x=='C') return y=='B';
	if(x=='D') return y=='F';
	if(x=='F') return y=='D';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000\n";
		return 0;
	}
	string x1,x2;
	x1+=s1[0];x1+=s1[1];
	x2+=s2[0];x2+=s2[1]; 
	if(x1!=x2){
		cout << "1000\n";
		return 0;
	}
	char y1=s1[2],y2=s2[2];
	if(!check1(y1,y2)){
		cout << "1100\n";
		return 0;
	}
	if(!check2(y1,y2)){
		cout << "1110\n";
		return 0;
	}
	cout << "1111\n";
	return 0;
}
