#include <bits/stdc++.h>
#define int long long
using namespace std;

bool way(char i){
	return i <= 'C';
}

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	#endif
	
	int a, c;
	string B, D;
	
	cin >> a >> B >> c >> D;
	
	int b = atoi(B.substr(0, 2).c_str()), d = atoi(D.substr(0, 2).c_str());
	char b1 = B[2], d1 = D[2];
	
	if(a == c){
		cout << "1";
		
		if(b == d){
			cout << "1";
			
			if(way(b1) == way(d1))
				cout << "1" << (min(b1, d1) + 1 + (!way(b1)) == max(b1, d1));
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	
	return 0;
}
