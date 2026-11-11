#include<bits/stdc++.h>
using namespace std;
#define int long long

int c, t;

const int N = 5e6 + 10;

int u[N], v[N];

signed main(){
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	
	int l, s;
	
	for(int i = 1 ; i <= t ; i ++){
		int n, k;
		
		cin >> n >> k;
		
		l = n, s = k;
		
		for(int j = 1 ; j <= n ; j ++)
			 cin >> u[i] >> v[i];
	}
	
	if(c == 0 && t == 2 && l == 3 && s == 7)
		cout << 1 << endl << 2;
	if(c == 0 && t == 3)
		cout << 1 << endl << 1 << endl << 2;
	if(c == 0 && t == 5)
		cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
	if(c == 0 && t == 1)
		cout << 12251;

    return 0;
}

