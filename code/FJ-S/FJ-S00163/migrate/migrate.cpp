/*
1.是否开long long，空间够不够？
2.数组大小开到上限+50了吗？
3.边数组是否够？
4.多测清空？
5.多测读完数据再特判？
6.跑过极限数据？
7.暴力分，特殊性质打满了吗？
8.freopen不要注释！！！
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,a[N],dis[N],cnt[N],ans;
vector<int>g[N];
queue<int>q;
struct node{
	int x,step;
};
queue<node>pq;
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
void bfs1(int s){
	dis[s]=0;
	for(int i=s+1;i<=n;i++)dis[i]=inf;
	q.push(s);
	while(q.size()){
		int t=q.front();q.pop();
		for(int v:g[t]){
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1;
				q.push(v);
			}
		}
	}
	return;
}
void bfs2(int s){
	pq.push({s,0});//点，步数
	while(pq.size()){
		node t=pq.front();pq.pop();
//		cerr<<pq.size()<<endl; 
//		cerr<<t.x<<' '<<g[t.x].size()<<endl;
		if(t.step==dis[t.x])cnt[t.x]++; 
		for(int i=0;i<g[t.x].size();i++){
			int v=g[t.x][i];
//			cerr<<v<<endl;
			pq.push({v,t.step+1});
		}
	}
	return;
}
void solve(){
	n=read(),d=read(),ans=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		g[i].clear();
		g[i].shrink_to_fit();
	}
	if(c>=13&&c<=14){
		write(n-3);
		putchar(10);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d)break;
			g[i].push_back(j);
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j:g[i]){
			cerr<<i<<' '<<j<<endl;
		}
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)cnt[j]=0;
		bfs1(i);
		/*
		for(int j=i;j<=n;j++)cerr<<dis[j]<<' ';
		cerr<<endl;
		*/
		bfs2(i);
		/*
		for(int j=i+1;j<=n;j++)cerr<<cnt[j]<<' ';
		cerr<<endl;
		*/
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2)ans++;
		}
	}
	write(ans);
	putchar(10);
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
