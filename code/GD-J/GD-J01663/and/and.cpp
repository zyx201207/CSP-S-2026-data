#include <bits/stdc++.h>
using namespace std;
int n, m, maxt = INT_MIN, p;
vector<int> an;
int main(){
	//ÌâÄ¿£ºand
	ios :: sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> p;
		if(p > maxt){
			maxt = p;
		}
	}
	cout << maxt;
	return 0;
}
