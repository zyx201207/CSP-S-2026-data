#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	bool f = c1 == c3;
	bool f1 = f && c2.substr(0, 2) == c4.substr(0, 2);
	char ch[2];
	ch[0] = c2.back();
	ch[1] = c4.back();
	sort(ch, ch + 2);
	bool f2 = f1 && ((ch[0] == 'A' && ch[1] == 'B') || (ch[0] == 'A' && ch[1] == 'C') || (ch[0] == 'B' && ch[1] == 'C') || (ch[0] == 'D' && ch[1] == 'F'));
	bool f3 = f2 && ((ch[0] == 'A' && ch[1] == 'B') || (ch[0] == 'B' && ch[1] == 'C') || (ch[0] == 'D' && ch[1] == 'F'));
	cout << f << f1 << f2 << f3;
	return 0;
}
