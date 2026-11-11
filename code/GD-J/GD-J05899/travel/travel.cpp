#include<bits/stdc++.h>
using namespace std;
int rcar, xcar;
int rloc, xloc;
char rseat, xseat;
int rpla, xpla;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	rcar = (c1[0] - '0') * 10 + (c1[1] - '0');
	xcar = (c2[0] - '0') * 10 + (c2[1] - '0');
	rloc = (s1[0] - '0') * 10 + (s1[1] - '0');
	xloc = (s2[0] - '0') * 10 + (s2[1] - '0');
	rseat = s1[2];
	xseat = s2[2];
	if(rseat == 'A' || rseat == 'B' || rseat == 'C') rpla = 1;
	else rpla = 2;
	if(xseat == 'A' || xseat == 'B' || xseat == 'C') xpla = 1;
	else xpla = 2;
	if(rcar != xcar) cout << "0000";
	else{
		cout << "1";
		if(rloc != xloc) cout << "000";
		else{
			cout << "1";
			if(rpla != xpla) cout << "00";
			else{
				cout << "1";
				if(rpla == 2) cout << "1";
				else{
					if(rseat == 'B' || xseat == 'B') cout << "1";
					else cout << "0";
				}
			}
		}
	}
	return 0;
} 
