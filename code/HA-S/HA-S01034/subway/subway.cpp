#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,u,v,b[200002][2];
bool bv[2000];
struct nooo{
	long long s,l;
}qp;
vector<nooo> a[2000000];
priority_queue<nooo> que;
bool operator<(nooo aa,nooo bb){
	return aa.l>bb.l;
}
void bfs(int nn,int mm){
	que.push({nn,0});
	memset(bv,0,sizeof(bv));
	while(!que.empty()){
		qp=que.top(),que.pop();
		if(bv[qp.s]||qp.l>d){
			continue;
		}
		bv[qp.s]=1;
//		cout<<qp.s<<" "<<qp.l<<"\n";
		if(qp.s==mm){
			d=min(d,qp.l);
		}
		for(int i=0;i<a[qp.s].size();i++){
			que.push({a[qp.s][i].s,qp.l+a[qp.s][i].l});
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	c=d;
	for(int i=1;i<=m;i++){
		cin>>v;
		a[i].push_back({i+m,v});
		a[i+m].push_back({i,v});
	}
	for(int k=1;k<=n;k++){
		cin>>u;
		for(int j=1;j<=u;j++){
			cin>>b[j][1]>>b[j][0];
		}
		for(int i=1;i<=u;i++){
			for(int j=i+1;j<=u;j++){
				a[b[i][1]+m].push_back({b[j][1]+m,b[i][0]+b[j][0]});
				a[b[j][1]+m].push_back({b[i][1]+m,b[i][0]+b[j][0]});
			}
		}
	}
//	for(int i=1;i<=m+m;i++){
//		for(int j=0;j<a[i].size();j++){
//			cout<<i<<":"<<a[i][j].s<<"="<<a[i][j].l<<"\n";
//		}
//	}
	while(q--){
		cin>>u>>v;
		d=114514917813676767;
		bfs(u,v);
		cout<<d<<"\n";
	}
	return 0;
}

