#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	int a,t;
};
int c,n,m,d,q,x,y,k;
vector<int>w;
vector<bool>vis;
queue<int>wai;
vector<vector<ll> >ans;
vector<vector<node> >a;
vector<vector<node> >mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	a.resize(n);
	ans.resize(m+1);
	mp.resize(n+m+2);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		a[i].resize(k);
		for(int j=0;j<k;j++){
			cin>>a[i][j].a>>a[i][j].t;
			mp[a[i][j].a].push_back({i+m+1,a[i][j].t});
			mp[i+m+1].push_back({a[i][j].a,a[i][j].t});
		}
	}
	for(int zt=1;zt<=m;zt++){
		vis.clear();
		vis.resize(m+n+2);
		ans[zt].resize(n+m+2,0x3f3f3f3f3f3f3f3f);
		for(int i=0;i<int(mp[zt].size());i++){
			ans[zt][mp[zt][i].a]=mp[zt][i].t;
			if(!vis[mp[zt][i].a]){
				vis[mp[zt][i].a]=1;
				wai.push(mp[zt][i].a);
			}
		}
		while(!wai.empty()){
			int noww=wai.front();
			wai.pop();
			vis[noww]=0;
			for(int i=0;i<int(mp[noww].size());i++){
				if(ans[zt][mp[noww][i].a]>ans[zt][noww]+mp[noww][i].t){
					ans[zt][mp[noww][i].a]=ans[zt][noww]+mp[noww][i].t;
					if(!vis[mp[noww][i].a]){
						vis[mp[noww][i].a]=1;
						wai.push(mp[noww][i].a);
					}
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<ans[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
