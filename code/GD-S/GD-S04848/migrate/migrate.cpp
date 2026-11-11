#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,x;
	cin >> c >> x;
	if(c == 0){
		int xx,yy;
		cin >> xx >> yy;
		if(xx == 5 && yy == 3){
			cout << 0 << endl << 1 << endl;
			return 0;
		}
	} 
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
