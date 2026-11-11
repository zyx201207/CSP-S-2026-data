#include<bits/stdc++.h> 
using namespace std;
int cR,cX;
string sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cR>>sr>>cX>>sx;
	if(cR!=cX)cout << "0000" << endl;
	else if(cR==cX&&sr[0]==sx[0]&&sr[1]==sx[1]){
		if((sr[2]=='A'||sr[2]=='B'||sr[2]=='C' && sx[2]=='A'||sx[2]=='B'||sx[2]=='C')||(sr[2]=='D'||sr[2]=='F' && sx[2]=='D'||sx[2]=='F')){
			if(sx[2]+1==sr[2]||sx[2]-1==sr[2]){
				cout << 1111 << endl;
			}else{
				cout << 1110 << endl;
			}
		}else{
			cout << 1100 << endl;
		}
	}else{
		cout << 1000 << endl;
	}
	return 0;
}
