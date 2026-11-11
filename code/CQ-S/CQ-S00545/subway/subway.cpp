#include<bits/stdc++.h>
#define ll long long
using namespace std;
int testcase,n,m,d,Q;
const int maxn = 510,maxm = 5e5 + 10;
ll w[maxm];
int k[maxn];
vector<int> a[maxn];
vector<ll> t[maxn];
vector<pair<int,ll> > tran[maxm];
ll floyd[maxn][maxn];
//

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>testcase>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]),t[i].resize(k[i]);
		for(int j=0;j<k[i];j++) {
			cin>>a[i][j]>>t[i][j];
			tran[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i != j) floyd[i][j] = 1e18;//¼Ç×¡£¡ÊÇ -1 Ó´£¡ 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int node = a[i][j];
			for(int x=0;x<tran[node].size();x++){
				if(tran[node][x].first == i) continue;
				int des = tran[node][x].first;
				if(floyd[i][des] > t[i][j] + tran[node][x].second){
					floyd[i][des] = floyd[des][i] = t[i][j] + tran[node][x].second;
				}
			}
		}
	}
	//floyd Faster!!!
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				floyd[i][j] = min(floyd[i][j],floyd[i][x] + floyd[x][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		ll ans = 1e18;
		for(int i=0;i<tran[x].size();i++){
			for(int j=0;j<tran[y].size();j++){
				int A = tran[x][i].first,B = tran[y][j].first;
				ll C = tran[x][i].second,D = tran[y][j].second;
				ans = min(ans,w[x] + w[y] + C + D + floyd[A][B]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

