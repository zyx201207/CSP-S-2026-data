#include<bits/stdc++.h>
using namespace std;
#define itn int
int ax,bx;
string ay,by;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> ax >> ay >> bx >> by;
	char aa = ay[0],ab = ay[1],ac = ay[2],ba = by[0],bb = by[1],bc = by[2];
	if(ax == bx){
		cout << 1;
		if(aa == ba && ab == bb){
			cout << 1;
			if(ac == 'A' || ac == 'B' || ac == 'C'){
				if(bc == 'A' || bc == 'B' || bc == 'C'){
					cout << 1;
					if(ac == 'B' || bc == 'B'){
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
				if(bc == 'F' || bc == 'D'){
					cout << 11;
				}
				else{
					cout << "00";
				}
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
