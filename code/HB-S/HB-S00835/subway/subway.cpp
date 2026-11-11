#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int c,n,m,d,q;
int station[N];
int k[505];
int a[505][N];
int t[505][N];
//int shortest(int start , int end){
//	int sum = station[start] + station[end];
//	for(int i = 1;i <= n;i ++){
//		for(int j = 1;j <= k[i]*2 + 1;j += 2){
	//		if(a[i][j] == start){
	//			
	//		}
	//	}
	//}
//}
int main(){
	cin >> c >> n >> m >> d >> q;
	freopen("subway.in", "r" , stdin);
	freopen("subway.out","w", stdout);
	for(int i = 1;i <= m;i ++)cin >> station[i];
	for(int j = 1;j <= n;j ++){
		cin >> k[i];
		for(int i = 1;i <= 2*k;i ++){
			if(i % 2)cin >> a[j][i];
			else cin >> t[j][i];
		}
	}
	for(int i = 1;i <= n;i ++){
		int st , ed;
		cin >> st >> ed;
		//cout << shortest(st , ed);
	}
	return 0;
}
