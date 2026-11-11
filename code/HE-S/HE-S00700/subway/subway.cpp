#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N],t[N];
struct PII{
	int b,t;
};
int ans=1e9;
int c,n,m,q,d;
bool st[N];
vector<pair<int,int>>e[N];
int solve1(int x,int y){
	queue<PII>q;
	q.push({x,w[x]});
	while(q.size()){
		int u=q.front().b,dis=q.front().t;
		q.pop();
		if(st[u]) continue;
		st[u]=true;
		if(u==y) ans=min(ans,dis+w[y]);
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(auto it:e[i]){
				if(it.first==u) flag=true,dis+=it.second;
			}
			if(flag){
				for(auto it:e[i]){
					if(it.first!=u) q.push({it.first,it.second+dis});
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int b,t;
			cin>>b>>t;
			e[i].push_back({b,t});
			e[b].push_back({i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e9;
		memset(st,0,sizeof st);
		cout<<solve1(x,y)<<'\n';
	}
	return 0;
} 
