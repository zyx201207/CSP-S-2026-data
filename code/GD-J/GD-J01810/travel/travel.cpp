#include <bits/stdc++.h>
using namespace std;
int go(char x){
	if (x=='D'|| x=='f') return 1;
	else return 0;
}
int goo(char x){
	if (x=='D') return 10;
	else if (x=='F') return 11;
	else if (x=='C') return 3;
	else if (x=='B') return 2;
	else return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a!=c){
		cout <<"0000";
		return 0;
	}
	else {
		if (b[1]!=d[1]){
			cout <<"1000";
			return 0;
		}
		else if (go(b[2])!=go(d[2])){
			cout <<"1100";
		}
		else if (abs(goo(b[2])-goo(d[2]))>1){
			cout <<"1110";
			return 0;
		}
		else {
			cout <<"1111";
			return 0;
		}
	}
} 
