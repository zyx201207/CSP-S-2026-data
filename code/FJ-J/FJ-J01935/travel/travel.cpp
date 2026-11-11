#include<bits/stdc++.h>
using namespace std;
int r, x;
string sr, sx;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r >> sr >> x >> sx;
	if (r==x){
		cout << 1;
		if ((sr[0]-'0')*10+sr[1]-'0'==(sx[0]-'0')*10+sx[1]-'0'){
			cout << 1;
			if ((sr[2]=='A'||sr[2]=='B'||sr[2]=='C') && (sx[2]=='A'||sx[2]=='B'||sx[2]=='C')){
				cout << 1;
				if ((sr[2]=='A'&&sx[2]=='C') || (sr[2]=='C'&&sx[2]=='A')){
					cout << 0;
				}else{
					cout << 1;}
			}else if ((sr[2]=='D'||sr[2]=='F') && (sx[2]=='D'||sx[2]=='F')){
				cout << 11;
			}else{
				cout << "00";}
		}else{
			cout << "000";}
	}else{
		cout << "0000";}
	return 0;
}
