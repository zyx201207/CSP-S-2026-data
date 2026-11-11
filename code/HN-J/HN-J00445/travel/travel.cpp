#include<bits/stdc++.h>
using namespace std;

string a, b, c, d;
char p1[3] = {'A', 'B', 'C'}, p2[2] = {'D', 'F'};

signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		if(b[0] == d[0] and b[1] == d[1]){
			cout << "1";
			bool s = 0;
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(i == j) continue;
					if((b[2] == p1[i] and d[2] == p1[j]) or (b[2] == p1[j] and d[2] == p1[i])){
						s = 1;
					}
				}
			}
			if((b[2] == 'D' and d[2] == 'F') or(b[2] == 'F' and d[2] == 'D')){
				s = 1;
			}
			if(s) cout << "1";
			else cout << "0";
		}
		else cout << "00";
	}
	else{
		cout << "000";
	}
	if((b[2] == 'D' and d[2] == 'F') or(b[2] == 'F' and d[2] == 'D')) cout << "1";
	else if((b[2] == 'A' and d[2] == 'B') or(b[2] == 'A' and d[2] == 'B')) cout << "1";
	else if((b[2] == 'B' and d[2] == 'C') or(b[2] == 'C' and d[2] == 'B')) cout << "1";
	else cout << "0";
	return 0;
}
