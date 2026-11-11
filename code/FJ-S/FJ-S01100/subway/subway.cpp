#include<bits/stdc++.h>
using namespace std;

const int maxn=505, maxm=500510;
const long long INF=2e18;

int c,n,m,d,q;
//n:地铁线路数
//m:地铁站数 

long long ans;
int w[maxm],k;
vector<pair<int, int> > mp[maxm];
bool flag[maxm];
//long long ss[maxm];

long long dfs(int s,  long long t, int y){
	if(s==y){
		return 0;
	}
	flag[s]=true;
	long long ans=INF;
	for(int i=0;i<mp[s].size();i++){
		int nxt=mp[s][i].first;
		long long time=mp[s][i].second;
		if(!flag[nxt]){
			ans=min(ans, dfs(nxt, t, y)+time);
		}
	}
	flag[s]=false;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cout<<INF;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			mp[m+i].push_back({a, t});
			mp[a].push_back({m+i, t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		memset(ss, INF, sizeof(ss));
//		cout<<ss[15];
		ans=dfs(x, 0, y);
//cout<<"我已出仓";
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
