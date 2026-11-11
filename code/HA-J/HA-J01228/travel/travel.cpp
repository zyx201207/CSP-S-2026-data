#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	string sa,sb;
	
	cin >> a >> sa;
	cin >> b >> sb;
	
	if(a != b) {
		cout << "0000";
		return 0;
	}
	
	int ac = sa[0] * 10 + sa[1];
	int bc = sb[0] * 10 + sb[1];
	
	if(ac != bc) {
		cout << 1000;
		return 0;
	}
	
	int la = sa[2], lb = sb[2];
	if ((la <= 'C' && lb >= 'D') || (la <= 'D' && lb >= 'C')) {
		cout << 1100;
		return 0;
	}
	
	int temp = abs (la - lb);
	if (temp == 1) {
		cout << 1111;
		return 0;
	} 
	cout << 1110;
	return 0;
}


