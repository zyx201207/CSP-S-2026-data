#include<bits/stdc++.h>
using namespace std;
int RC,RP,XC,XP;//Rchexiang Rpai Xchexiang Xpai
char RZ,XZ;//Rzuowei Xzuowei
string S1,S2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>RC>>S1>>XC>>S2;
	RP=(S1[0]-'0')*10+(S1[1]-'0');
	RZ=S1[2];
	XP=(S2[0]-'0')*10+(S2[1]-'0');
	XZ=S2[2];
	cout<<(RC==XC)<<(RC==XC && RP==XP)<<
	(RC==XC && RP==XP && ((RZ>='D' && XZ>='D') || (RZ<='C' && XZ<='C')))<<
	(RC==XC && RP==XP && ((RZ>='D' && XZ>='D') || (RZ<='C' && XZ<='C' && (RZ=='B' || XZ=='B'))));
	return 0;
}
