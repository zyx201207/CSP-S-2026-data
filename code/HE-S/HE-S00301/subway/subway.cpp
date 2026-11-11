#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,v;
};
struct cmp{
	bool operator()(const node &x,const node &y)const{
		return x.v>y.v;
	}
};
priority_queue<node,vector<node>,cmp> p;
int c,n,m,d,q,w[501000];
int de(int s,int e,priority_queue<node,vector<node>,cmp> p2){
	int dis[501000];
	for(int i=1;i<=m+n;i++){
		dis[i]=1e9;
	}
	dis[s]=0;
	for(int i=1;i<=n+m;i++){
		node t=p2.top();
		for(int j=1;j<=n+m;j++){
			dis[j]=min(dis[j],dis[t.a]+t.v);
		}
		p2.pop();
	}
	return dis[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int x,y;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			p.push({m+i,x,y});
			p.push({x,m+i,y});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<de(s,e,p)+w[s]+w[e]<<endl;
	}
	return 0;
}
