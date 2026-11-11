#include<bits/stdc++.h>
using namespace std;
const int N = 1100;
long long w[N];
long long a[N] , t[N] ,dis[N][N];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	memset(dis , 0x3f , sizeof dis);
	for(int i = 1;i <= m;++ i)
		cin >> w[i];
	for(int i = 1;i <= n;++ i){
		int k;
		cin >> k;
		for(int j = 1;j <= k;++ j){
			cin >> a[j] >> t[j];
			for(int l = 1;l < j;++ l)
				dis[a[j]][a[l]] = dis[a[l]][a[j]] = min(t[l] + t[j], dis[a[l]][a[j]]);
		}
	}
	//floyd
	for(int k = 1;k <= m;++ k)
		for(int i = 1;i <= m;++ i)
			if(i != k)
				for(int j = 1;j <= m;++ j)
					if(i != j && j != k)
						dis[i][j] = min(dis[i][k] + dis[k][j] , dis[i][j]);
	int l , r;
	while(q --){
		cin >> l >> r;
		cout << dis[l][r] + w[l] + w[r] << '\n';
	}
}