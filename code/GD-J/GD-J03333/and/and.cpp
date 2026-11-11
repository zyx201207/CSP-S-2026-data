#include<iostream>
#include<vector>
using namespace std;
#define ull unsigned long long
#define N 200005
ull a[N], d[N], n, m, ans = 0;
bool vis[N];
void dfs(int step){
	if(step < m){
		for(int i = 1;i <= n;i++){
			if(!vis[i]){
				d[step+1] = a[i];
				vis[i]=1;
				dfs(step+1);
				vis[i]=0;
			}
		}
		return ;
	}
	ull tmp = d[1];
	for(int i = 2;i <= m;i++){
		tmp &= d[i];
	}
	ans = max(ans, tmp);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
