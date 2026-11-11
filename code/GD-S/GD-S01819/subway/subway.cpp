#include <bits/stdc++.h>
using namespace std;
const int M=500001;
struct node {
	int nd,ln,dis;
};
struct rule {
	bool operator()(const node &x,const node &y) {
		return x.nd>y.nd;
	}
};
unordered_map<int,int> st[M];
int c,n,m,d,q,x,y,w[M],dis[M][25];
vector<node> e[M];
priority_queue<node,vector<node>,rule> hp;
int dij(int s,int f) {
	memset(dis,0x3f,sizeof(dis));
	hp.push({s,0,w[s]});
	int yp=dis[s][0];
	dis[s][0]=w[s];
	while(!hp.empty()) {
		node tp=hp.top();
		hp.pop();
		for(const node &eg:e[tp.nd]) {
			int new_l=tp.dis+eg.dis;
			if(tp.ln==eg.ln) new_l-=(st[tp.nd][eg.ln]<<1);
			if(dis[eg.nd][eg.ln]==yp) {
				dis[eg.nd][eg.ln]=new_l;
				hp.push({eg.nd,eg.ln,new_l});
			}
		}
	}
	int tmp=INT_MAX;
	for(int i=1;i<=d;i++)
		tmp=min(tmp,dis[f][i]);
	return tmp+w[f];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	/*
	n条线路，m个站，q问
	每个地铁站最多有d条线路经过
	*/
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++) {
		cin>>k;
		int ys=0;
		for(int o=1,s,t;o<=k;o++) {
			cin>>s>>t;
			st[s][i]=t;
			if(ys) {
				int we=st[s][i]+st[ys][i];
				e[s].push_back({ys,i,we});
				e[ys].push_back({s,i,we});
			}
			ys=s;
		}
	}
	while(q--) {
		cin>>x>>y;
		cout<<dij(x,y)<<'\n';
	}
	return 0;
} 
