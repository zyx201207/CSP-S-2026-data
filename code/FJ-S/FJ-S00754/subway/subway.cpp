#include<bits/stdc++.h>
using namespace std;
#define int long long
int T=1,c,n,m,d,q,ans=1e18;
int w[500005];
struct node{
	int id,t;
};
vector<node> a[505];
vector<int> v[500005];

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].id>>a[i][j].t;
			v[a[i][j].id].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				if(v[x][i]==v[y][j]){
					ans=min(ans,a[v[x][i]][i].t+a[v[y][j]][j].t);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
