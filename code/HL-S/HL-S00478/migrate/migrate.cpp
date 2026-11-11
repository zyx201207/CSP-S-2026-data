#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A = 2e6+5;
ll a[A] ,  dis[15][15] , vis[15][15] , n ,d;
ll j(ll fgh){
	if(fgh < 0) return -fgh;
	else return fgh;
}
void dfs_dis(int fa , int step , ll len){
	if(len > dis[fa][step]) return ;
	if(step==n) return ;
	if(len < dis[fa][step]) {
		dis[fa][step] = len;
	}
	for(int i = step + 1;i <= n;i ++){
		if(j(a[i] - a[step]) <= d){
			dfs_dis(fa , i , len + 1);
		}
	}
}
int main(){
	//vis[A][B] 第b号点有vis[a][b]条来自a的路径
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll C , T;
	cin >> C >> T;
	while(T --){
		memset(a , 0 , sizeof(a));
		memset(vis , 0 , sizeof(vis));
		ll ans = 0 ;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) cin >> a[i];
		for(int i = 1;i < n;i ++){
			dfs_dis(i , i , 0);
		}
//		for(int i = 1;i <= n;i ++){
//			for(int j = 1;j <= n;j ++){
//				cout << dis[i][j] << " ";
//			}
//			cout << '\n';
//		}
		cout << 0 << '\n';
		
	}
	return 0;
}