#include<bits/stdc++.h>
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define int long long
#define pii pair<int, int>
using namespace std; 

string a, b, c, d;

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		if(b.substr(0, 2) == d.substr(0, 2)){
			cout << 1;
			char c1 = b[2], c2 = d[2];
			if((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D'))
				cout << 1 << (abs(c1 - c2) == 1 ? 1 : 0);
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
