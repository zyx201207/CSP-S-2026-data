#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[200010];
int n,d;
int ans;
int a_cnt;
void dfs(int u,int en,int cnt){
//	cout << "进入" << u << '\n';
	if(u == en){
//		cout << "找到了，返回\n";
		if(cnt < ans){
//			cout << "更新最短路径计数\n";
			ans = cnt;
			a_cnt = 1;
		}else if(cnt == ans){
//			cout << "最短路径计数++\n";
			a_cnt++;
		}
		return ;
	}
	for(int i = u+1;i <= en;i ++){
		if(x[i] - x[u] <= d){
//			cout << "发现可以去" << i << "过去\n";
			dfs(i,en,cnt+1);
		}else{
			break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> x[i];
		}
		int aans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = i+1;j <= n;j ++){
//				cout << "搜索" << i << "到" << j << "__________________\n";
				ans = 1e9;
				a_cnt = 0;
				dfs(i,j,0);
				if(a_cnt == 2){
//					cout << "路径数量满足\n";
					aans++;
				}
			}
		}
		cout << aans << '\n';
	}
	return 0;
}
