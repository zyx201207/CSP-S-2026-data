#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int zhan,v,t;
};
int c,n,m,d,q,k[505],w[500005],dist[505][505];
vector<node>g[505];
int spfa(int st,int ed){
	queue<node>q;
	q.push({1,st,w[st]});
	while(q.size()){
		node t=q.front();
		q.pop();
		if(t.v==ed)
			return t.t;
		for(node x:g[t.v]){
			q.push({!t.zhan,x.v,t.t+x.t});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			g[a].push_back({0,i,t});
			g[i].push_back({1,a,t});
		}
	}
	while(q--){
		int st,ed;cin>>st>>ed;
		cout<<spfa(st,ed)<<"\n";
	}
	return 0;
}
//Oct31==Dec25? 
//我是上午写关注洛谷@Iain_的那个人，***S的题目太***难了 
