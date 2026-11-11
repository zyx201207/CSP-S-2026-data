#include<bits/stdc++.h>
#define int long long

using namespace std;

int c,n,m,d,q;
vector<int> w;
struct Node{
	int a,t;
	Node(int _a,int _t){
		a = _a;
		t = _t;
	}
	Node();
	bool operator>(const Node &other)const{
		return t>other.t;
	}
};
vector<vector<Node> > mp1,mp2;
int vis[1005][1005];

void floyd(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			if(i==k) continue;
			for(int j = 1;j<=n;j++){
				if(i==j || k==j) continue;
				if(vis[i][k]!=vis[0][0] && vis[k][j]!=vis[0][0]){
					vis[i][j] = min(vis[i][j],vis[i][k]+vis[k][j]);
				}
			}
		}
	}
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	w.assign(m+1,0);
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	mp1.assign(n+1,vector<Node>(0));
	mp2.assign(m+1,vector<Node>(0));
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			mp1[i].emplace_back(a,t);
			mp2[a].emplace_back(i,t);
		}
	}
	vis[0][0] = LLONG_MAX;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			vis[i][j] = LLONG_MAX;
		}
	}
	for(int i = 1;i<=n;i++){
		vis[i][i] = 0;
		for(size_t j = 0;j<mp1[i].size();j++){
			int dc = mp1[i][j].a;
			for(size_t k = 0;k<mp2[dc].size();k++){
				if(i==mp2[dc][k].a) continue;
				vis[i][mp2[dc][k].a] = min(vis[i][mp2[dc][k].a],mp1[i][j].t+mp2[dc][k].t);
			}
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans = LLONG_MAX;
		for(size_t i = 0;i<mp2[x].size();i++){
			for(size_t j = 0;j<mp2[y].size();j++){
				ans = min(ans,vis[mp2[x][i].a][mp2[y][j].a]+mp2[x][i].t+mp2[y][j].t);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
//ypy is so cute
//cq-j00585 && cq-s00583
