#include <bits/stdc++.h>
using namespace std;
string x, x1, y, y1;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> x >> x1 >> y >> y1;
	if(x != y) cout << "0000" << endl;
	else{
		string a = "", b = "";
		for(int i = 0; i < x1.size() - 1; i++) a = a + x1[i];
		for(int i = 0; i < y1.size() - 1; i++) b = b + y1[i];
		if(a != b) cout << "1000" << endl;
		else{
			int c = int(x1[x1.size() - 1] - 'A'), d = int(y1[y1.size() - 1] - 'A');
			if((c >= 3 && d >= 3) || (c < 3 && d < 3)){
				if((c + 1 == d || d + 1 == c) && !((c == 2 && d == 3) || (c == 3 && d == 2))) cout << "1111" << endl;
				else cout << "1110" << endl;
			}else cout << "1100" << endl;
		}
	}
	return 0;
}
