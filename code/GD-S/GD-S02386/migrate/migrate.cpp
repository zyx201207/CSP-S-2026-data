#include<bits/stdc++.h>
using namespace std;
const int M = 2e6 + 9;
int c, t;
int n, d, a[M];
struct E{
	int shu, mi;
}ans[M];
long long sum;
void dfs(int step, int id){
	if(id > a[n]){
		return;
	}
	if(!ans[id].shu){
		ans[id].shu++;
		ans[id].mi = step;
	}
	if(step == ans[id].mi){
		ans[id].shu++;
	}
	for(int i = 1; i <= n; i++){
		if(a[id] + d >= a[id + i]){
			dfs(step + 1, id + i);
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		memset(ans, 0, sizeof(ans));
		cin >> n >> d;
		int maxx = -1;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i] > maxx){
				maxx = a[i];
			}
		}
		
		dfs(1, 1);
		sum= 0;
		for(int i = 1; i <= n; i++){
			if(ans[i].shu == 2){
				sum++;
			}
		}
		cout << 0 << '\n';
	}
	fclose(stdin);
	fclose(stdout);
}
// 0 2
// 4 2
// 1 2 3 4
// 5 2 
// 1 2 3 4 5
