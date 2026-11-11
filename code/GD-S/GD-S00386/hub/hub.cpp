#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,s,head[N],dis[N],cnt,k,T,a[N],b[N],c[N],l[N];
bool vis[N];
struct edge{
	int to,di,nxt;
}e[N];
inline void add(int u,int v,int d){
	e[++cnt]=(edge){v,d,head[u]};
	head[u]=cnt;
}
struct node{
	int pos,dis;
	bool operator <(const node &a)const{
		return a.dis<dis;
	}
};
priority_queue<node>q;
inline void djl(){
	q.push((node){s,0});
	while(!q.empty()){
		node a=q.top();
		q.pop();
		int x=a.pos;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].di){
				dis[y]=dis[x]+e[i].di;
				if(!vis[y])q.push((node){y,dis[y]});
			}
		}
	}
}
int ans[5010][5010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int text;
	cin>>text;
	cin>>T;
	cin>>m>>n;
	cnt=0;
	for(int i=1;i<=m-1;i++){
		int u,v;
		cin>>u>>v;
		add(u,v,1);
		add(v,u,1);
	}
	for(int ii=1;ii<=m;ii++){
		for(int i=0;i<=m+1;i++)dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
		s=ii;
		dis[s]=0;
		djl();
		for(int i=1;i<=m;i++)
			ans[ii][i]=dis[i];
	}
	if(n<=100){
		int t=0;
		for(int i=1;i<=m;i++){
			int lll=0;
			for(int j=1;j<=m;j++)t=max(t,ans[i][j]),l[j]=ans[i][j];
			for(int j=1;j<=m;j++){
				int p=0;
				if(j!=i){
					for(int k=1;k<=m;k++){
						p=max(p,min(l[k],ans[j][k]));
					}
					if(p<=t){
						lll++;
						t=p;
						for(int k=1;k<=m;k++){
							l[k]=min(l[k],ans[j][k]);
						}
					}
				}
				if(lll==n)break;
			}
			
		}
		cout<<t;
	}
	else{
		for(int i=1;i<=m;i++){
			l[i]=ans[i][1];
			for(int j=1;j<=m;j++){
				l[i]=min(ans[i][j],l[i]);
			}
		}
		sort(l+1,l+m+1);
		cout<<l[1];
	}
	return 0;
}

