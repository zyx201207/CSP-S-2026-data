#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200050], cnt;
void dfs(int x, long long y, int z){
	if(x > m){
		cnt = max(cnt, y);
		return;
	}
	for(int i = z;i <= n;i++){
		if(x == 1){
			y = a[i];
			dfs(x+1, y, i+1);
		}else{
			dfs(x+1, y&a[i], i+1);
		}
	}
}
int main(){
	//Trick||Treat!
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}dfs(1, 0, 1);
	cout << cnt;
	return 0;
} 
