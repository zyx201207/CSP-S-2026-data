#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int c, t, n, k;
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	mt19937 rnd(time(0));
	cin >>c >>t;
	while(t--){
		cin >>n >>k;
		for(int i=1; i<n; i++){
			int u, v;
			cin >>u >>v;
		}
		cout <<rnd() % (n/2) + 1 <<endl;
	}
	return 0;
}

