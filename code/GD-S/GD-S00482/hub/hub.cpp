#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5005,inf=1e18;
int cas;
int n,k;
int us[N],cntt;
vector<int>e[N];
void dfs(int u,int f){
	if(us[u]&&!us[f]&&f!=0) cntt++;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	int T;
	cin>>cas>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int msk=0;msk<1<<n;msk++){
			cntt=0;
			for(int i=1;i<=n;i++) us[i]=0;
			for(int i=0;i<n;i++){
				if((msk>>i)&1){
					cntt++;
					us[i]=1;
				}
			}
			if(cntt!=k) continue;
			cntt=0;
			dfs(1,0);
			cout<<cntt<<"\n";
		}
	}
	return 0;
}
/*

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/
