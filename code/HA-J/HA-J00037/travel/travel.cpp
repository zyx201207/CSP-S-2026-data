#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio (false);
	cin.tie (0);

	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cout << "1";
		if((s1[0] == s2[0]) && (s1[1] == s2[1])){
			cout << "1";
			if(((s1[2] < 'D') && (s2[2] < 'D')) || ((s1[2] >= 'D') && (s2[2] >= 'D'))){
				cout << "1";
				
				bool xl = false;
				if(s1[2] == 'A'&&s2[2] == 'B'){
					xl = true;
				}else if( ( (s1[2] == 'B') && (s2[2] == 'A') ) || ( (s1[2] == 'B') && (s2[2] == 'C') ) ){
					xl = true;
				}else if(( (s1[2] == 'C') && (s2[2] == 'B') )){
					xl = true;
				}else if(( (s1[2] == 'D') && (s2[2] == 'F') )){
					xl = true;
				}else if(( (s1[2] == 'F') && (s2[2] == 'D') )){
					xl = true;
				}
				
				if(xl){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	cout << "\n";
	return 0;
}

//finish at 9:20