#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
string c1, s1, c2, s2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int jk = (s1[0] - '0') * 10 + (s1[1] - '0');
	int kl = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(c1 == c2){
		cout << "1";
		if(jk == kl){
			cout << "1";
			if(s1[2] <= 'C' && s2[2] >= 'D' || s1[2] >= 'D' && s2[2] <= 'C'){
				cout << "00";
				return 0;
			}
			else{
				cout << "1";
				if(abs((s1[2] - '0') - (s2[2] - '0')) == 1){
					cout << "1";
					return 0;
				}
				else cout << "0";
			}
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
}
