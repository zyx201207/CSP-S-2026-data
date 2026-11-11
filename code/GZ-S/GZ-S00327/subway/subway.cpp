//GZ-S00327 夏宇森 中央民族大学附属中学贵阳学校 
#include<bits/stdc++.h>
using namespace std;
const int N = 520, M = 5e5+10;
int cebianhao, n, m, d ,q;
int w[M], dp[M], x1, x2;
struct node{
	int to, time;
};
vector<node> dt[N];
vector<int> zhan[M];
void solve(int now, int fa){
	memset(dp, 0, sizeof dp);
	for(int i = 0; i <= zhan[now].size(); ++i){
		for(int j = 0; j <= dt[i].size(); ++j){
			node nxt = dt[zhan[now][i]][j];
			if(nxt.to == fa) continue;
			dp[nxt.to] = min(dp[nxt.to], dp[now]+dt[zhan[now][i]][now].time+dt[zhan[now][i]][nxt.to].time);
			solve(nxt.to, now);
		}
	}
	if(now == x2) return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp, 0, sizeof dp);
	scanf("%d%d%d%d%d",&cebianhao, &n, &m, &d, &q);
	for(int i = 1; i <= m; ++i){
		scanf("%d", & w[i]);
	}
	for(int i = 1; i <= n; ++i){
		int dtn; cin >> dtn;
		for(int k = 1; k <= dtn; ++k){
			scanf("%d%d", &x1, &x2);
			dt[i].push_back((node){x1, x2});
			zhan[x1].push_back(i);
		}
	}
	for(int i = 1; i <= q; ++i){
		scanf("%d%d", &x1, &x2);
		solve(x1, -1);
		cout << dp[x2]+w[x1]+w[x2]<<endl;
	}
	return 0;
}
