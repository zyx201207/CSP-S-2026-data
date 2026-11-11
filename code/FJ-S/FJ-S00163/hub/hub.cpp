/*
1.是否开int，空间够不够？
2.数组大小开到上限+50了吗？
3.边数组是否够？
4.多测清空？
5.多测读完数据再特判？
6.跑过极限数据？
7.暴力分，特殊性质打满了吗？
8.freopen不要注释！！！
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50;
int c,T,n,k,num,col[N],ans;
int head[N],nxt[N],to[N],tot;
bitset<N>vis,vis2;
queue<pair<int,int> >q;
queue<int>qq;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+48);
	else write(x/10),putchar(x%10+48);
	return;
}
void add(int u,int v){
	nxt[++tot]=head[u];
	head[u]=tot;
	to[tot]=v;
	return;
}
int d(int x){
	while(q.size())q.pop();
	vis2.reset();
	vis2.set(x);
	q.push({x,0});
	while(q.size()){
		pair<int,int>t=q.front();q.pop();
		if(vis[t.first])return t.second;
		for(int i=head[t.first];i;i=nxt[i]){
			int v=to[i];
			if(vis2[v])continue;
			vis2.set(v);
			q.push({v,t.second+1});
		}
	}
	return 0;
}
int calc(){
	int g=0;
	for(int i=1;i<=n;i++)g=max(g,d(i));
	return g;
}
void bfs(int s){
	qq.push(s);
	while(qq.size()){
		int t=qq.front();qq.pop();
		for(int i=head[t];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]&&!col[v]){
				col[v]=1;
				qq.push(v);
			}
		}
	}
	return;
}
bool check(){
	for(int i=1;i<=n;i++)col[i]=0;
	num=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&!col[i]){
			num++;
			if(num>=3)return 0;
			bfs(i);
		}
	}
	return 1;
}
//当前节点、已遍历节点数量，已标记节点数量、父亲节点
/*
void dfs(int x,int y,int z,int fa){
	if(z>k||y>n||n-y<k-z)return;
	if(z==k){
		for(int i=1;i<=n;i++)cout<<vis[i];
		cout<<endl;
		ans=min(ans,calc());
		return;
	}
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa)continue;
		vis.set(v);
		dfs(v,y+1,z+1,x);
		vis.reset(v);
		dfs(v,y+1,z,x);
	}
	return;
}
*/
void solve(){
	n=read(),k=read(),tot=0,ans=INT_MAX;
	vis.reset();
	for(int i=1,u,v;i<=n-1;i++){
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	if(c>=13&&c<=14){
		int m=(n/2);
		if(n==k)write(0);
		else write(max(1,(n-k*2)/8+2));
		putchar(10);
		return;
	}
//	dfs(1,0,0,0);
	for(int i=0;i<=(1<<n)-1;i++){
		vis=(i<<1);
		if(vis.count()!=k||!check())continue;
//		for(int j=1;j<=n;j++)cerr<<vis[j];
//		cerr<<endl;
		ans=min(ans,calc());
	}
	write(ans);
	putchar(10);
	for(int i=1;i<=n;i++)head[i]=0;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
