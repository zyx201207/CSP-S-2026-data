#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1145141],k[1145141],a[510][10010],t[510][10010];
int bfs(int x,int y,int b,int c,int d){
	queue<int> e;
	return 0;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++) cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j++) cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1,x,y ; i <= q ; i++){
		cin >> x >> y;
		int sum = w[x] + w[y];
		sum = bfs(x,y,x,1,0);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
