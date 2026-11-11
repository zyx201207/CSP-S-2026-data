#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int qi,zhong;
int k[505];
bool vis[1000005] = {0};
vector<int> st[1000005],wri;
vector<int> new_v;
struct egg{int a,t;};
egg ed[505][1000005];
vector<int> dp = {0x3f};
int Bfs(int l,int r,int cost){
	if(dp[l] > cost){dp[l] = cost;return 0;}
	if(l == r)return cost;
	int lmy = 1;
	while(lmy <= wri[l]){
		int pp = st[l][lmy];
		for(long long i = 1;i <= k[pp] and ed[pp][i].a != l;++i){
			vis[ed[pp][i].a] = true;
			cost = (cost > Bfs(i, r , ed[pp][l].t))?cost:Bfs(i, r , ed[pp][l].t);
			}
		new_v.push_back(pp);
		lmy++;
	}
	return cost;
}
int tim[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1;i <= m;++i)cin >> tim[i];
	
	for(long long i = 1;i <= n;++i){
		cin >> k[i];
		for(long long j = 1;j <= k[i];++j){
			int aj,tj;
			cin >> aj >> tj;
			st[aj].push_back(i);
			wri[aj]++;
			ed[i][j].a = aj;
			ed[i][j].t = tj;
		}		
	}
	for(int  i = 1;i <= q;++i){
		cin >> qi >> zhong;
		cout << tim[qi] + tim[zhong] + Bfs(qi,zhong,0) << endl;
	}
	return 0;
}	
	
	
