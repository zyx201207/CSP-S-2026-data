#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << "0000";
	}else{
		cout << 1;
		if(b[0] != d[0] || b[1] != d[1]){
			cout << "000";
		}else{
			cout << 1;
			char x = b[2],y = d[2];
			if((x == 'D' && y == 'F') || (x == 'F' && y == 'D')){
				cout << 11;
			}else{
				if((x >= 'D' && y < 'D') || (x < 'D' && y >= 'D')) cout << "00";
				else if(abs(x-y) == 1) cout << 11;
				else{
					if((x == 'C' && y < 'C') || (x < 'C' && y == 'C')) cout << 10;
					else cout << "00";
				}
			}
		}
	}
	return 0;
}

