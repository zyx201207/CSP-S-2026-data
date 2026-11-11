#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1;
string xn1,xn2,n1,n2;
void file() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
} 
bool check(char c1,char c2) {
	if(((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))) return true;
	if(((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))) return true;
	else return false;
}
bool checkBeside(char c1,char c2) {
	int mn = min(c1,c2);
	int mx = max(c1,c2);
	if(mn=='D'&&mx=='F') return true;
	if(mn=='A'&&mx=='B') return true;
	if(mn=='B'&&mx=='C') return true;
	return false;
}
void solve() {
	cin >> xn1 >> n1 >> xn2 >> n2;
	string p1 = n1.substr(0,2);
	string p2 = n2.substr(0,2);
	// cout << p1 << ' ' << p2 << '\n';
	char c1 = n1[2];
	char c2 = n2[2];
	if(xn1!=xn2) cout << "0000\n";
	else {
		if(p1!=p2) cout << "1000\n";
		else {
			if(!check(c1,c2)) cout << "1100\n";
			else {
				if(!checkBeside(c1,c2)) cout << "1110\n";
				else cout << "1111\n";
			} 
		}
	}
}
int main() {
	file();
	int t=1;
	// cin >> t;
	while(t--) solve();
}
/*
02 02B 02 01A
02 01A 03 01A
02 01C 02 01A
*/
