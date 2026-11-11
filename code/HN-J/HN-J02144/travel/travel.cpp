#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct tv{
	string cx;
	string zw;
	int intzw;
};

int main()
{
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	tv c,s;
	cin >> c.cx >> c.zw >> s.cx >> s.zw;
	int answer[4] = {0, 0, 0, 0};
	
	if (c.zw[2] == 'A'){
		c.intzw = 1;
	}else if (c.zw[2] == 'B'){
		c.intzw = 2;
	}else if (c.zw[2] == 'C'){
		c.intzw = 3;
	}else if (c.zw[2] == 'D'){
		c.intzw = 4;
	}else{
		c.intzw = 5;
	}
	if (s.zw[2] == 'A'){
		s.intzw = 1;
	}else if (s.zw[2] == 'B'){
		s.intzw = 2;
	}else if (s.zw[2] == 'C'){
		s.intzw = 3;
	}else if (s.zw[2] == 'D'){
		s.intzw = 4;
	}else{
		s.intzw = 5;
	}
	
	if (c.cx == s.cx) {
		answer[0] = 1;
	}
	if (answer[0] == 1 && c.zw[0] == s.zw[0] && c.zw[1] == s.zw[1]) {
		answer[1] = 1;
	}
	if (answer[1] == 1 && ((c.intzw <= 3 && s.intzw <= 3) || (c.intzw > 3 && s.intzw > 3))) {
		answer[2] = 1;
	}
	if (answer[2] == 1 && (c.intzw + 1 == s.intzw || c.intzw - 1 == s.intzw || s.intzw + 1 == c.intzw || s.intzw - 1 == c.intzw)){
		answer[3] = 1;
	}
	freopen("travel.out", "w", stdout);
	cout << answer[0] << answer[1] << answer[2] << answer[3] << endl;
	
	return 0;
}
