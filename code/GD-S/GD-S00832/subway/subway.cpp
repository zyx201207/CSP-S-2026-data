#include<bits/stdc++.h>
using namespace std;
int v[500005],ww[500005][505];
vector<pair<int,int> > du[505];
unordered_map<int,int> vis[505];
int top[505];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,b,s,t,w;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		vector<int> sv(x+1),sw(x+1);
		for(int j=1;j<=x;j++){
			cin>>sv[j]>>sw[j];
			vis[i][++top[i]]=sv[j];
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<=x;k++){
				if(j!=k) du[sv[j]].push_back({sw[j],sv[k]});
				else ww[sv[j]][i]=sw[j];
			}
		}
	}
	while(q--){
		cin>>s>>t;
		for(auto it=vis[s].begin();it!=vis[s].end();it++){
			int bb=(*it).second;
			deque<pair<int,int> > dq;
			vector<int> dp(m+1,1e9);
			dq.push_back({s,bb});
			dp[s]=v[s]+ww[s][bb];
			while(!dq.empty()){
				auto tmp=dq.front(); dq.pop_front();
				if(tmp.first==t){
					cout<<dp[t]+v[t]<<"\n";
					break;
				}
				for(int i=0;i<du[tmp.first].size();i++){
					if(vis[du[tmp.first][i].second].count(tmp.second)&&dp[du[tmp.first][i].second]>dp[tmp.first]+du[tmp.first][i].first){
						dp[du[tmp.first][i].second]=dp[tmp.first]+du[tmp.first][i].first;
						dq.push_front({du[tmp.first][i].second,tmp.second});
					}else if(dp[du[tmp.first][i].second]>dp[tmp.first]+du[tmp.first][i].first+ww[tmp.first][tmp.second]){
						dp[du[tmp.first][i].second]=dp[tmp.first]+du[tmp.first][i].first+ww[tmp.first][tmp.second];
						for(auto it=vis[du[tmp.first][i].second].begin();it!=vis[du[tmp.first][i].second].end();it++) dq.push_back({du[tmp.first][i].second,(*it).second});
					}
				}
			}	
		}
	}
	return 0;
}
