#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1000000;
const Long MOD = 998244353;
const Long INF = 0x3f3f3f3f3f3f3f3f;

inline void solve(){
	string ab, ax, bb, bx;
	cin >> ab >> ax >> bb >> bx;
	
	string ret = "0000\n";
	if(ab == bb){
		ret[0] = '1';
		if(ax[0] == bx[0] && ax[1] == bx[1]){
			ret[1] = '1';
			if((ax[2] <= 'C') == (bx[2] <= 'C')){
				ret[2] = '1';
				if(abs((ax[0] - bx[0]) * 10 + ax[1] - bx[1]) + abs(ax[2] - bx[2]) <= 1){
					ret[3] = '1';
				}
			}
		}
	}
	cout << ret;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
//	int t; cin >> t; while(t--)
	{
		solve();
	}
	
	return 0;
}
