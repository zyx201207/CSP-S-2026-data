#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> cr >> sr >>cx >>sx;
	if(cr[0] == cx[0] && cr[1] == cx[1]){
		cout << 1;
		if(sr[0] == sx[0] && sr[1] == sx[1]){
			cout << 1;
			if((sr[2]=='F' && sx[2]=='D')||(sr[2]=='D' && sx[2]=='F')){
				cout << 1;
			}
			else if((sr[2]=='C'||sr[2]=='A'||sr[2]=='B')&&(sx[2]=='C'||sx[2]=='A'||sx[2]=='B')){
				cout << 1;
			}
			else cout << 0;
			
			if( sr[2] == 'A'){
				if(sx[2] == 'B'){
					cout << 1;
				}
				else cout << 0;
			}
			else if(sr[2] == 'B'){
				if(sx[2] == 'A'||sx[2] == 'C'){
					cout << 1;
				}
				else cout << 0;
			}
			else if(sr[2] == 'C'){
				if(sx[2] == 'B'){
					cout << 1;
				}
				else cout << 0;
			}
			else if(sr[2] == 'D'){
				if(sx[2] == 'F'){
					cout << 1;
				}
				else cout << 0;
			}
			else if(sr[2] == 'F'){
				if(sx[2] == 'D'){
					cout << 1;
				}
				else cout << 0;
			}
			else cout << 0;
		}
		else cout <<"000";
	}
	else cout << "0000";
//	cout << (int)(sr[2]-sx[2]);
	return 0;
}
/*
02 01A 02 01B
*/
