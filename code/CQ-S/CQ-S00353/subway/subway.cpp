#include<bits/stdc++.h>
//想出了一个O(d^2(k+q)) 
//CCF的评测机是不是真能1s跑5e8
//如果不是这道题我只有个92
//是的话就是100
//其实都可以
//也就8分罢了 
//实力!!!!!!!! 
using namespace std;
using ll=long long;
int c,n,m,d,q;
ll val[500010];
ll mat[510][510];
vector<pair<int,ll> >bel[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>val[i];
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		while(cnt--){
			int x,t;
			cin>>x>>t;
			bel[x].emplace_back(i,t);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)mat[i][j]=1e15;
		mat[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<bel[i].size();j++){
			for(int k=1;k<bel[i].size();k++){
				int u=bel[i][j].first;
				int v=bel[i][k].first;
				if(bel[i][j].second+bel[i][k].second<mat[u][v]){
					mat[u][v]=mat[v][u]=bel[i][j].second+bel[i][k].second;
				}
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mat[j][i]=mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
			}
		}
	}
	ll res=0;
	while(q--){
		int s,t;
		cin>>s>>t;
		res=1e18;
		for(int i=0;i<bel[s].size();i++){
			for(int j=0;j<bel[t].size();j++){
				int u=bel[s][i].first;
				int v=bel[t][j].first;
				
				res=min(res,val[s]+val[t]+mat[u][v]+bel[s][i].second+bel[t][j].second);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 
*/

