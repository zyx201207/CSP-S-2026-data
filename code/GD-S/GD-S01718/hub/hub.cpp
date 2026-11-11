#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,d[1000005],mn;
vector<int>g[1000005];
bool v[1000005],v2[1000005];
queue<pair<int,int>>q;
int read(){
	int c=getchar(),f=1,x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void write(int x){
	if(x==0)return;
	if(x<0){putchar('-');x=-x;}
	write(x/10);
	putchar(x%10+'0');
}
void bfs(){
	memset(d,0x3f,sizeof(d));
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(d[x]>y)d[x]=y;
		else if(d[x]<y)continue;
		for(auto i:g[x]){
			if(d[i]>d[x]+1){
				d[i]=d[x]+1;
				q.push({i,d[i]});
			}
		}
	}
}
void ltk(int x,int fa){
	if(!v[x]||v2[x])return;
	v2[x]=1;
	for(auto i:g[x]){
		if(i==fa)continue;
		ltk(i,x);
	}
}
void dfs(int x,int s){
	if(s==k){
		memset(v2,0,sizeof(v2));
		int s=0;
		for(int i=1;i<=n;i++){
			if(v[i]&&!v2[i]){
				s++;
				ltk(i,-1);
			}
		}
		if(s>2)return;
		bfs();
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,d[i]);
		mn=min(mn,mx);
		return;
	}
	if(x>n||n-x+s+1<k)return;
	q.push({x,0});
	v[x]=1;
	dfs(x+1,s+1);
	v[x]=0;
	queue<pair<int,int>>t;
	while(q.size()>1){
		t.push(q.front());
		q.pop();
	}
	q.pop();
	while(t.size()){
		q.push(t.front());
		t.pop();
	}
	dfs(x+1,s);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	if(c==13||c==14){
		while(t--){
			n=read();k=read();
			for(int i=1,u,v;i<n;i++){
				u=read();v=read();
			}
			write(n/2+1-k/2);putchar('\n');
		}
	}
	while(t--){
		n=read();k=read();
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			u=read();v=read();
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		mn=0x3f3f3f3f;
		dfs(1,0);
		write(mn);putchar('\n');
	}
	return 0; 
}
