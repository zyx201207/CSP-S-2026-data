#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int N = 1e3 + 5;

void miku(){
	
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	
	if (s1 == s3) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return ;
	}
	
	if (s2[0] == s4[0] && s2[1] == s4[1]) cout << 1;
	else{
		cout << 0 << 0 << 0;
		return ;
	}
	
	if (((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && (s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C')) || ((s2[2] == 'D' || s2[2] == 'F') && (s4[2] == 'D' || s4[2] == 'F'))) cout << 1;
	else{
		cout << 0 << 0;
		return ;
	}
	
	if ((s2[2] == 'A' && s4[2] == 'B') || (s2[2] == 'B' && (s4[2] == 'A' || s4[2] == 'C')) || (s2[2] == 'C' && s4[2] == 'B') || (s2[2] == 'D' && s4[2] == 'F') || (s2[2] == 'F' && s4[2] == 'D')) cout << 1;
	else cout << 0;
	
	return ;
}

int main(){
	
	freopen("travel.in", "r" , stdin);
	freopen("travel.out", "w" , stdout);
	
	miku();
	
	return 0;	
}
