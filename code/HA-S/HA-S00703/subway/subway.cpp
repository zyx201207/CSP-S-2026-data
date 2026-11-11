#include<bits/stdc++.h>
using namespace std;
struct sb{
	int to,time;
};
int n,c,m,d,q;
int w[500005];
vector<sb> edge[505];
int dj(int b,int e){
	queue<sb> p;
	p.push({edge[b].to,edge[b].time})
	while(!p.empty()){
		int u=p.top().to,v=p.top().time;
		p.pop();
		for(auto o:edge[u]){
			if(edge[u].time+v<o.time){
				o.time=edge[u].time+v;
				p.push({o.to,o.time});
			}
		}
	}
	return edge[e].time;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,y;
			cin>>y>>t;
			edge[i].push_back({y,t});
		}
	}
	for(int i=1;i<=q;i++){
		int begin,end;
		cin>>begin>>end;
		cout<<dj(begin,end);
	}
	return 0;
}
