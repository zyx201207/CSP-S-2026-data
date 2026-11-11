#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool Adj(char a, char b) {
	if(a<='C' && b<='C') return 1;
	if(a>'C' && b>'C') return 1;
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	int tmp=(c1==c2);
	
	cout<<tmp;
	
	tmp=(tmp && s1[0]==s1[0] && s1[1]==s2[1]);
	
	cout<<tmp;
	
	tmp=(tmp && Adj(s1[2], s2[2]));
	
	cout<<tmp;
	
	tmp=(tmp && abs(s1[2]-s2[2])==1);
	
	cout<<tmp;
	return 0;
}
