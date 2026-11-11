#include<bits/stdc++.h>
using namespace std;
bool tc(char a,char b){
	if(a == 'A'){
		if(b == 'B' || b == 'C') return true;
	}
	if(a == 'B'){
		if(b == 'A' || b == 'C') return true;
	}
	if(a == 'C'){
		if(b == 'A' || b == 'B') return true;
	}
	if(a == 'D' && b == 'F'){
		return true;
	}
	if(a == 'F' && b == 'D'){
		return true;
	}
	return false;
}
bool xl(char a,char b){
	if(a == 'A' && b == 'B'){
		return true;
	}
	if(a == 'B' && b == 'C'){
		return true;
	}
	if(a == 'C' && b == 'B'){
		return true;
	}
	if(a == 'B' && b == 'A'){
		return true;
	}
	if(a == 'D' && b == 'F'){
		return true;
	}
	if(a == 'F' && b == 'D'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	string p1="",p2="";
	for(int i=0;i < 2;i++){
		p1+=s1[i];
		p2+=s2[i];
	}
	if(p1 == p2) cout << 1;
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(tc(s1[2],s2[2])) cout << 1;
	else{
		cout << 0 << 0;
		return 0;
	}
	if(xl(s1[2],s2[2])) cout << 1;
	else cout << 0;
	return 0;
}
