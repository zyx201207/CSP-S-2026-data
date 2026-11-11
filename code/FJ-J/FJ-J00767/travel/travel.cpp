#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string sa,sb;
	cin >> a;
	cin >> sa;
	cin >> b;
	cin >> sb;
	if(a!=b) cout << "0000\n";
	else if(sa[0]!=sb[0] || sa[1]!=sb[1]) cout << "1000\n";
	else if(sa[2]=='A' && sb[2]=='B') cout << "1111\n";
	else if(sa[2]=='A' && sb[2]=='C') cout << "1110\n";
	else if(sa[2]=='A' && sb[2]=='D') cout << "1100\n";
	else if(sa[2]=='A' && sb[2]=='F') cout << "1100\n";
	else if(sa[2]=='B' && sb[2]=='A') cout << "1111\n";
	else if(sa[2]=='B' && sb[2]=='C') cout << "1111\n";
	else if(sa[2]=='B' && sb[2]=='D') cout << "1100\n";
	else if(sa[2]=='B' && sb[2]=='F') cout << "1100\n";
	else if(sa[2]=='C' && sb[2]=='A') cout << "1110\n";
	else if(sa[2]=='C' && sb[2]=='B') cout << "1111\n";
	else if(sa[2]=='C' && sb[2]=='D') cout << "1100\n";
	else if(sa[2]=='C' && sb[2]=='F') cout << "1100\n";
	else if(sa[2]=='D' && sb[2]=='A') cout << "1100\n";
	else if(sa[2]=='D' && sb[2]=='B') cout << "1100\n";
	else if(sa[2]=='D' && sb[2]=='C') cout << "1100\n";
	else if(sa[2]=='D' && sb[2]=='F') cout << "1111\n";
	else if(sa[2]=='F' && sb[2]=='A') cout << "1100\n";
	else if(sa[2]=='F' && sb[2]=='B') cout << "1100\n";
	else if(sa[2]=='F' && sb[2]=='C') cout << "1100\n";
	else if(sa[2]=='F' && sb[2]=='D') cout << "1111\n";
	return 0;
}
