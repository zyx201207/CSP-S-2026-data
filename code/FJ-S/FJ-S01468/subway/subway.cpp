#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=505,M=5e5+5;
ll c,n,m,k,d,q,w[N],len[N],x,y,dir[M],ans,u;
struct node{
	int a,t;
};
vector<node> line[N],mid[M];
struct Node{
	int u,from;ll t;
};
bool operator<(Node o,Node h){
	return o.t<h.t;
}
priority_queue<Node> Q;
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll dis(int s,int e){
	for(int i=1;i<=m;i++) dir[i]=1e18;
	dir[s]=0;Q.push({s,0,0});
	while(!Q.empty()){
		Node p=Q.top();Q.pop();
		u=p.u;
		if(u==e||p.t>dir[u]) continue;
		for(int i=0;i<(int)(mid[u].size());i++){
			int road=mid[u][i].a,pos=mid[u][i].t;
			if(road==p.from) continue;
			ll val=p.t+line[road][pos].t;
			for(int j=pos+1;j<len[road];j++){
				ll v=line[road][j].a,edge=line[road][j].t;
				if(dir[v]>val+edge){
					dir[v]=val+edge;
					Q.push({v,road,dir[v]});
				}
			}
		}
	}
	return dir[e]+w[s]+w[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		len[i]=read();
		for(int j=0;j<len[i];j++){
			x=read();y=read();
			line[i].push_back({x,y});
			mid[x].push_back({i,j});
		}
	}
	for(int i=1;i<=q;i++){
		x=read();y=read();
		write(min(dis(x,y),dis(y,x)));
		putchar('\n');
	}
}
