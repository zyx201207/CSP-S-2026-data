#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1001000];
int n, k;
bool flag[1001000];
bool flag1[1010000];
void dfs1(int cur, int fa){
	if(vec[cur].size() == 1) return ;
	for(int i : vec[cur]){
		if(i == fa) continue;
		if(flag[i]){
			flag1[i] = 1;
			dfs1(i, cur);
		}
	}
}
bool check(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(!flag[i]) continue;
		if(flag1[i]) continue;
		cnt++;
		if(cnt == 3) break;
		dfs1(i, 0);
	}
	for(int i = 1;i <= n;i++) flag1[i] = 0;
	return (cnt <= 2);
}
int minn = 0x3f3f3f3f3f3f3f3f;
void dfs2(int cur, int fa, int st){
	if(minn < st) return ;
	if(flag[cur]){
		minn = min(minn, st);
		return ;
	}
	for(int i : vec[cur]){
		if(i == fa) continue;
		dfs2(i, cur, st + 1);
	}
}
int minn1 = 0x3f3f3f3f3f3f3f3f;
void dfs(int cur, int cnt){
	if(n - cur + 1 + cnt < k) return ;
	if(cnt == k){
		if(check()){
			int maxn = 0;
			for(int i = 1;i <= n;i++){
				if(flag[i]){
					
				}else{
					dfs2(i, 0, 0); 
					maxn = max(maxn, minn);
					minn = 0x3f3f3f3f3f3f3f3f;
				}
			}
		minn1 = min(minn1, maxn);
//		cout << 123456 << endl;
		}
		return ;
	}
	dfs(cur + 1, cnt);
	flag[cur] = 1;
	dfs(cur + 1, cnt + 1);
	flag[cur] = 0;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			int u, v;
			cin >>u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u); 
		}
		dfs(1, 0);
		cout << minn1 << endl;
		minn1 = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1;i <= n;i++){
			vec[i].clear();
		}
		break;
	}
} 
/*0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/
