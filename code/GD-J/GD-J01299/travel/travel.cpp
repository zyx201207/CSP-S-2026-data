#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c,s,ci,si;
	cin >> c >> s >> ci >> si;
	if(c != ci){
		cout << "0000";
		return 0;
	}
	else{
		if(s[0] != si[0] || s[1] != si[1]){
			cout << "1000";
			return 0;
		}
		else{
			if(s[2] == 'A' || s[2] == 'B' || s[2] == 'C'){
				if(si[2] != 'A' && si[2] != 'B' && si[2] != 'C'){
					cout << "1100";
					return 0;
				}
				else{
					if(s[2] == 'A'){
						if(si[2] != 'B'){
							cout << "1110";
							return 0;
						}
						else{
							cout << "1111";
							return 0;
						}
					}
					if(s[2] == 'B'){
						cout << "1111";
						return 0;
					}
					if(s[2] == 'C'){
						if(si[2] != 'B'){
							cout << "1110";
							return 0;
						}
						else{
							cout << "1111";
							return 0;
						}
					}
				}
			}
			if(s[2] == 'D' || s[2] == 'F'){
				if(si[2] != 'D' && si[2] != 'F'){
					cout << "1100";
					return 0;
				}
				else{
					cout << "1111";
					return 0;
				}
			}
		}
	}
	return 0;
} 
