#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
string r1, r2, x1, x2;
bool fl1, fl2, fl3, fl4;
signed main(){
	fin("travel.in");
	fout("travel.out");
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1 == x1) fl1 = 1;
	if(fl1 && r2[0] == x2[0] && r2[1] == x2[1]) fl2 = 1;
	if(fl2){
		if(r2[2] == 'A' || r2[2] == 'B' || r2[2] == 'C'){
			if(x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C'){
				fl3 = 1;
			}
		}else{
			if(x2[2] == 'D' || x2[2] == 'F'){
				fl3 = 1;
			}
		}
	}
	if(fl3 && (abs(r2[2] - x2[2]) == 1) || (r2[2] == 'D' && x2[2] == 'F') || (r2[2] == 'F' && x2[2] == 'D')) fl4 = 1;
	cout << fl1 << fl2 << fl3 << fl4 << '\n';
	return 0;
}
//8:47
