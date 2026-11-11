#include<bits/stdc++.h>
using namespace std;
long long read() {
	long long f=1,x=0;
	char ch;
//	ch=getchar_unlocked();
	ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
//		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
//		ch=getchar_unlocked();
	}
	return f*x;
}
struct Node {
	long long a,b;
};
vector<Node>e[1000005];
int c,n,m,d,Q;
int w[500005];
//int a[505][25],t[505][25];
int top,s,t;
long long ans;
long long dis[1000005];
priority_queue<Node,vector<Node>,greater<Node> >q;
operator >(const Node aa,const Node bb) {
	return aa.b>bb.b;
}
bool bo[1000005];
void dij() {
	for(int i=1; i<=top; i++) {
		dis[i]=INT_MAX;
		bo[i]=false;
	}
	q.push((Node){s,0});
	dis[s]=0;
//	bo[s]=true;
	while(!q.empty()) {
		Node u=q.top();
		q.pop();
		if(bo[u.a])continue;
		bo[u.a]=true;
		for(Node i:e[u.a]) {
			dis[i.a]=min(dis[i.a],dis[u.a]+i.b);
			q.push((Node){i.a,dis[i.a]});
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1; i<=m; i++) {
//		cin>>w[i];
		w[i]=read();
	}
	top=m;
	for(int i=1; i<=n; i++) {
		long long k;
		cin>>k;
		long long x,y;
		x=read();
		y=read();
//		cin>>x>>y;
		top++;
		e[x].push_back({top,y});
		e[top].push_back({x,y});
		for(int i=2; i<=k; i++) {
			x=read();
			y=read();
//			cin>>x>>y;
			top++;
			e[x].push_back({top,y});
			e[top].push_back({x,y});
			e[top].push_back({top-1,0});
			e[top-1].push_back({top,0});
		}
	}
	while(Q--) {
		s=read();
		t=read();
//		cin>>s>>t;
		dij();
		printf("%lld\n",(long long)(dis[t]+w[s]+w[t]));
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

