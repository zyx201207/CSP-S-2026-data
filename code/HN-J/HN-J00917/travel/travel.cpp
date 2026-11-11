#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, c, d;
char ch1, ch2;

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> ch1 >> c >> d >> ch2;
	if(a == c){
		cout << '1';
		if(b == d){
			cout << '1';
			if(ch1 <= 'C' && ch2 <= 'C' || ch1 >= 'D' && ch2 >= 'D'){
				cout << '1';
				if(ch1 > ch2) swap(ch1, ch2);
				if(ch2 == 'F' && ch1 == 'D' || ch2 - ch1 == 1) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
