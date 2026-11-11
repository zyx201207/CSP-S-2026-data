#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,qz,ans=1e18;
int w[500010];
vector<int> e[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u;
		cin>>u>>qz;
		for(int j=2;j<=k;j++){
			int v;
			cin>>v>>qz;
			e[u].push_back(v);
			u = v;
		}
	}
	/*
	for(int i=1;i<=m;i++){
		//cout<<"i : "<<i<<"   ";
		for(auto v:e[i]){
			cout<<v<<" ";
		}
		cout<<'\n';
	}*/
	while(q--){
		ans = 0;
		int u,v;
		cin>>u>>v;
		cout<<3*qz<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
