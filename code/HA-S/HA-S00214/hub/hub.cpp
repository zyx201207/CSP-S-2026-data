#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,inf=1e18;
int T=1,c;
int n,k,f[N/100][N/100];
vector<int>e[N];
void init(){
	for(int i(1);i<=n;++i){
		for(int j(1);j<=n;++j){
			f[i][j]=inf;
		}
	}
}
void minroad(){
	for(int k(1);k<=n;++k){
		for(int i(1);i<=n;++i){
			for(int j(1);j<=n;++j){
				if(i==j) continue;
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
}
void solve(){
	cin>>n>>k;
	for(int i(1);i<n;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(c==1){
		
		return;
	}
	if(c==7){
		
		return;
	}
	cout<<rand(); 
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
