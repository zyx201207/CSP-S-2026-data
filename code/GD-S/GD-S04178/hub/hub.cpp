#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k,ui[1000005],vi[1000005],head[1000005],tot,all,f[1000005],dis[1000005],ans;
bool vis[1000005];
queue<int> que;
struct edge{
	int to,next; 
} e[2000005];
void link(int x,int y) {
	++tot;
	e[tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
int find(int x) {
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
bool check(int x) {
	int s=0,s2=0;
	for(int i=0;i<n;i++) {
		s+=((x>>i)&1);
		f[i+1]=i+1;
	}
	if(s!=k) return false;
	for(int i=1;i<n;i++) {
		if(((x>>(ui[i]-1))&1)&&((x>>(vi[i]-1))&1)) {
			f[find(ui[i])]=find(vi[i]);
		}
	}
	for(int i=1;i<=n;i++) {
		if(!((x>>(i-1))&1)) continue;
		if(find(i)==i) s2++;
	}
	if(s2>2) return false;
	else return true;
}
int D(int x) {
	int u,v,mx=0;
	for(int i=1;i<=n;i++) {
		if((x>>(i-1))&1) {
			dis[i]=0;
			que.push(i);
			vis[i]=true;
		}
		else {
			dis[i]=1e9;
			vis[i]=false;
		}
	}
	while(!que.empty()) {
		u=que.front();
		mx=max(mx,dis[u]);
		que.pop();
		for(int i=head[u];i;i=e[i].next) {
			v=e[i].to;
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=true;
			que.push(v);
		}
	}
	return mx;
}
void solve() {
	all=1<<n;
	ans=1e9;
	for(int sta=1;sta<all;sta++) {
		if(!check(sta)) continue;
		ans=min(ans,D(sta));
	}
}
int D7(int x,int y) {
	int u,v,mx=0;
	for(int i=1;i<=n;i++) {
		dis[i]=1e9;
		vis[i]=false;
	}
	dis[x]=0;
	que.push(x);
	vis[x]=true;
	dis[y]=0;
	que.push(y);
	vis[y]=true;
	while(!que.empty()) {
		u=que.front();
		mx=max(mx,dis[u]);
		que.pop();
		for(int i=head[u];i;i=e[i].next) {
			v=e[i].to;
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=true;
			que.push(v);
		}
	}
	return mx;
}
void solve7() {
	ans=1e9;
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<=n;j++) {
			ans=min(ans,D7(i,j));
		}
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==7||c==11||c==12) {
		while(t--) {
			scanf("%d%d",&n,&k);
			tot=0;
			for(int i=1;i<=n;i++) {
				head[i]=0;
			}
			for(int i=1;i<n;i++) {
				scanf("%d%d",&ui[i],&vi[i]);
				link(ui[i],vi[i]);
				link(vi[i],ui[i]);
			}
			solve7();
			printf("%d\n",ans);
		} 
		return 0;
	}
	while(t--) {
		scanf("%d%d",&n,&k);
		tot=0;
		for(int i=1;i<=n;i++) {
			head[i]=0;
		}
		for(int i=1;i<n;i++) {
			scanf("%d%d",&ui[i],&vi[i]);
			link(ui[i],vi[i]);
			link(vi[i],ui[i]);
		}
		solve();
		printf("%d\n",ans);
	} 
	return 0;
}/*0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/
