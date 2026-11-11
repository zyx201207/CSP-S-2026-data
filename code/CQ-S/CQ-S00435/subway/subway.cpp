#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> p[500005],q[500005];
int w[500005];
map<pair<int,int>,int> f,g;
int c,d,a;
void check(int x){
	queue<int> t;
	map<pair<int,int>,int> ma;
	t.push(x);
	ma[{x,x}]=1;
	while(!t.empty()){
		int tx=t.front();
		t.pop();
		for(auto v:q[tx]){
			for(auto u:p[v]){
				if(ma[{tx,u}]) continue;
				ma[{tx,u}]=1;
				if(!f[{x,u}]) f[{x,u}]=f[{x,tx}]+g[{u,v}]+g[{tx,v}];
				else f[{x,u}]=min(f[{x,u}],f[{x,tx}]+g[{u,v}]+g[{tx,v}]);
				t.push(u);
			}
		}
			
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>a;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			p[i].push_back(a);
			q[a].push_back(i);
			g[{a,i}]=t;
		}
	}
	
	while(a--){
		int x,y,ex,ey;
		cin>>x>>y;
		if(!f[{x,y}])check(x);
		cout<<f[{x,y}]+w[x]+w[y]<<endl;
	}
	return 0;
}

