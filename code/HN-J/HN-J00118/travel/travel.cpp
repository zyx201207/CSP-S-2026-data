#include<bits/stdc++.h>
using namespace std;
string rx,rz,xx,xz;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rx >> rz >> xx >> xz;
	if(rx == xx) cout << '1';
	else cout << '0';
	if(rx == xx && rz[0] == xz[0] && rz[1] == xz[1]) cout << '1';
	else cout << '0';
	if(rx == xx && rz[0] == xz[0] && rz[1] == xz[1]){
		char x = rz[2],y = xz[2];
		if(x == 'A' && y == 'B' || x == 'B' && y == 'A' || x == 'A' && y == 'C' || x == 'C' && y == 'A' || x == 'B' && y == 'C' || x == 'C' && y == 'B' || x == 'D' && y == 'F' || x == 'F' && y == 'D'){
			cout << '1';
		}else{
			cout << '0';
		}
	}else{
		cout << 0;
	}
	if(rx == xx && rz[0] == xz[0] && rz[1] == xz[1] && abs(int(rz[2] - xz[2])) == 1){
		char x = rz[2],y = xz[2];
		if(x == 'D' && y == 'C' || x == 'C' && y == 'D'){
			cout << 0;
		} else {
			cout << 1;
		}
	}else cout << 0;
	return 0;
}
