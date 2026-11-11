#include <bits/stdc++.h>
using namespace std;

int c, t;
const int num = 2e6+4;
int x[num];

long long way(int x, int y){	//返回有多少条路线 
	
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		int n;	//island_number
		long long d;	//distance
		cin >> n >> d;
		int ld, rd;	//表示最左或者最右可以到达的地方 
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(way(i)) 
			}
		}
	}
	return 0;
}
