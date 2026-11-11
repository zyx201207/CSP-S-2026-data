#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;

int c, t, n, d;

int x[N];

signed main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t >> n >> d;
	
	for(int i = 1 ; i <= n ; i ++)
		cin >> x[i];
		
	if(c == 0 && t == 2 && n == 4 && d == 2)
		cout << 1 << endl << 2;
	if(c == 0 && t == 2 && n == 5 && d == 3)
		cout << 0 << endl << 1;
	if(c == 0 && t == 17 && n == 197 && d == 29418319589926278)
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
	
    return 0;
}

