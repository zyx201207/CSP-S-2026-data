#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+100;
int w[N];
int di[N];
vector<pair<int,int> > ed[N];
struct node{
	int x;
	int step;
	bool operator<(const node oth)const{
		return step>oth.step;
	}
};
void dij(int x){
	for(int i=1;i<=n;i++) di[i]=1e15;
	priority_queue<node> q;
	q.push({x,w[x]});
	di[x]=w[x];
	while(!q.empty()){
		node f=q.top();
		q.pop();
		for(auto i:ed[f.x]){
			if(di[i.first]>di[f.x]+i.second){
				di[i.first]=di[f.x]+i.second;
				q.push({i.first,di[i.first]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int x1,x2,y1,y2;
		if(x==1){
			cin>>x1>>x2;
			continue;
		}
		cin>>x1>>y1>>x2>>y2;
		ed[x1].push_back({x2,y1+y2});
		ed[x2].push_back({x1,y1+y2});
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<di[v]+w[v]<<"\n";
	}
	return 0;
}

