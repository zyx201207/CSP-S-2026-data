#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2){
		cout << "0000" << "\n";
	}else{
		string a = s1.substr(0,2);
		string b = s2.substr(0,2);
		if(a != b){
			cout << "1000" << "\n";
		}else{
			char x = s1[2];
			char y = s2[2];
			if((('A' <= x and x <= 'C') and ('D' <= y and y <= 'E')) or (('D' <= x and x <= 'E') and ('A' <= y and y <= 'C'))){
				cout << "1100" << "\n";
			}else{
				int s = (x - 'A');
				int t = (y - 'A');
				if(abs(s - t) > 1){
					cout << "1110" << "\n";
				}else{
					cout << "1111" << "\n";
				}
			}
		}
	}
	
	return;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
} 
