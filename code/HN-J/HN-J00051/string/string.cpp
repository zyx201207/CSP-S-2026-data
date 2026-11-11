#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n=0,L=0,a=0,ci=0; 
	string S="",b="";
	cin >> n;
	for (int i=1;i<=n;i++) {
	cin >> a >> b; 
	L+=a;
	for (int i=1;i<=a;i++) S+=b;
}
	for (int i=0;i<=L/2;i++) {
		if(S[i]!=S[L-i]) {
		S[L-i]=S[i];
		ci++;}}
cout << ci;
	return 0;
}
