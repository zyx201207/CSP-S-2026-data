#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int x, y;
	string a, b;
	cin >> x >> a >> y >> b;
	
	int p = 0, u = 0, t = 0, v = 0, cnt = 1;
	for (int i = a.size() - 1; i >= 0; i --){
		if ('A' <= a[i] && a[i] <= 'F') u = a[i] - 'A' + 1;
		else p = p + (a[i] - '1' + 1) * cnt;
		if ('A' <= b[i] && b[i] <= 'F') v = b[i] - 'A' + 1;
		else t = t + (b[i] - '1' + 1) * cnt;
		cnt *= 10;
	} 
	
	if (x == y){
		cout << "1";
		if (p == t){
			cout << "1";
			if ((u <= 3 && v <= 3) || (u >= 4 && v >= 4)){
				cout << "1";
				if (abs(u - v) == 1){
					cout << "1";
				}else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	
	

	return 0;
}

