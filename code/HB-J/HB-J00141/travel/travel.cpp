#include <bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool check1(char a,char b){
	if(('A'<=a && a<='C' && 'A'<=b && b<='C') || ('D'<=a && a<='F' && 'D'<=b && b<='F')){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	if(cr==cx){
		cout << 1;
		if(sr[0]==sx[0] && sr[1]==sx[1]){
			cout << 1;
			if(check1(sr[2],sx[2])){
				cout << 1;
				if(sr[2]==sx[2]-1 || sr[2]-1==sx[2]){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
