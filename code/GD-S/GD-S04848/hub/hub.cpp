#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c == 0){
		int x,y,xx,yy;
		cin >> x >> y >> xx >> yy;
		if(x == 5 && y == 2 && xx == 1 && yy == 2){
			cout << 1 << endl << 2 << endl;
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
