#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int s1i,s2i;
int s(int a){
	return a-'0';
}

bool sss(char st1, char st2){
	if (st1=='A' and st2=='B') return true;
	if (st1=='B' and st2=='A') return true;
	if (st1=='B' and st2=='C') return true;
	if (st1=='C' and st2=='B') return true;
	if (st1=='D' and st2=='F') return true;
	if (st1=='F' and st2=='D') return true;
	if (st1=='A' and st2=='C') return true;
	if (st1=='C' and st2=='A') return true;
	return false;
}

bool ss(char st1, char st2){
	if (st1=='A' and st2=='B') return true;
	if (st1=='B' and st2=='A') return true;
	if (st1=='B' and st2=='C') return true;
	if (st1=='C' and st2=='B') return true;
	if (st1=='D' and st2=='F') return true;
	if (st1=='F' and st2=='D') return true;
	return false;
}

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) cout << 1;
	else cout << 0;
	s1i=10*s(s1[0])+s(s1[1]);
	s2i=10*s(s2[0])+s(s2[1]);
	if (s1i==s2i){
		cout << 1;
		if (sss(s1[2], s2[2])) cout << 1;
		else cout << 0;
		if (ss(s1[2], s2[2])) cout << 1;
		else cout << 0;
	} 
	else{
		cout << 0;
		cout << 0;
		cout << 0;
	} 
	return 0;
}
