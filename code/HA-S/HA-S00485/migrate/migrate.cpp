#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n, d, a[100010]={0}, c, t, f[5006][5006]; int visited[5006][5006];
//long long min1(long long a, long long b){
//	if( a> b) return a;
//	return b;
//}
void dfs(int x, int y, int l){
	//f[y][x] = min(f[y][x], a[y] - a[x]);
	if(f[y][x] > l){
		f[y][x] = l;
		visited[y][x] = 1;
	}else if(f[y][x] == l){
		visited[y][x]++;
	}
	if(x == n){
		return ;
	}
	for(int i =x+1; i<=n; i++){
		if(a[i] - a[x] <= d){
			dfs(i, y, l+1);
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i =1; i<=n; i++){
			for(int j =i+1; j<=n; j++) f[i][j] = 999999999999; 
		}
		for(int i =1; i<=n; i++){
			cin>>a[i];
		}
		//dfs()
		for(int i = n; i>=1; i--){
			dfs(i, i, 0);
		}
		long long a=0;
		for(int i =1; i<=n; i++){
			for(int j = i+1; j<=n; j++){
				if(visited[i][j] == 2){
				//	cout<<i<<" "<<j;
				 a++;
				}
			}
		}
		cout<<a<<'\n';
	}
	return 0;
}
