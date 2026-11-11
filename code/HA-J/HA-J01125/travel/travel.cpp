#include <bits/stdc++.h>
using namespace std;
int stoint(string s, bool flag){
	if (flag){
		return (s[0] - '0') * 10 + (s[1] - '0');
	}else return (s[2] - 'A' + 1);
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int x1, x2, cnt = 4;
	string s1, s2;
	cin >> x1 >> s1 >> x2 >> s2;
	if (x1 == x2){
		cout << 1;
		cnt--;
		if (stoint(s1, true) == stoint(s2, true)){
			cout << 1;
			cnt--;
			int y1 = stoint(s1,false), y2 = stoint(s2,false);
			if ((y1 <= 3 && y2 <= 3) || (y1 >= 4 && y2 >= 4)){
				cout << 1;
				cnt--;
				if (abs(y1 - y2) == 1){
					cout << 1;
					cnt--;
				}
			}
		}
	}
	for (int i = 1; i <= cnt; i++) cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
