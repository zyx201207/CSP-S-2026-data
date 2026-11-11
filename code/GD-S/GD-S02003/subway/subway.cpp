#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q;
const int N = 510, M=5e5+55;
int w[M],k[N];
vector<int>a[N],t[N];
struct edge{
	int x,y;
};
vector<edge>e[M];
int vis[M];
struct node{
	int x,s;
	bool operator<(const node& w)const{
		return w.s<s;
	} 
};

void dij(int st,int en,int id) {	
	priority_queue<node>q;
	q.push({st,0});
	vis[st]=id;
	while(q.size()){
		node u=q.top();
		q.pop();
		
		if(u.x==en){
			cout<<w[en]+u.s+w[st]<<'\n';
			return;
		}
		
		for(int i=0;i<e[u.x].size();i++){
			int x=e[u.x][i].x,y=e[u.x][i].y;
			for(int j=0;j<k[x];j++){
				int to=a[x][j];
				if(vis[to]==id)continue;
				vis[to]=id;
				q.push({to,u.s+t[x][j]+y});
			}
		}
	}
}

inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	
	return x;
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) {
		w[i]=read();
	}
	for(int i=1;i<=n;i++) {
		k[i]=read();
		for(int j=1;j<=k[i];j++) {
			int x,y;
			x=read(),y=read();
			a[i].push_back(x);
			t[i].push_back(y);
			e[x].push_back({i,y});
		}
	}
	
	for(int i=1;i<=q;i++){
		int st,en;
		st=read(),en=read();
		dij(st,en,i);
	}
	return 0;
}
