#include <bits/stdc++.h>
using namespace std;

const int N = 1005 , M = 30005;
int timef[M];
bool isblue[M];

struct node{
	int left , right ,id ,t;
};
node edge[M];
int edgewho[M];
int cnt;
int c , n , m , d , q;

int Ford(int from , int to){
	isblue[from] = true;
	for (int i = 1 ; i <= m ; ++ i){
		for (int j = 1 ; j <= cnt ; ++ j){
			
		}
	}
}

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cnt = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; ++ i){
		cin >> timef[i];
	}
//	int ans = 0;
	for (int i = 1 ; i <= n ; ++ i){
		int k;
		cin >> k;
		int x , xt , y , yt;
		cin >> x >> xt;
		while (k --){
			cin >> y >> yt;
			node tmp;
			tmp.left = x;
			tmp.right = y;
			tmp.t = xt + yt;
			tmp.id = i;
			edge[++ cnt] = tmp;
			
			x = y;
			xt = yt;
		}
	}
	while (q--){
		int from , to;
		cin >> from >> to;
		
	}
	return 0;
}
