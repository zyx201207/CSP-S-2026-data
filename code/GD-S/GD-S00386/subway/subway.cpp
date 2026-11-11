#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,s,head[N],dis[N],cnt,k,T,a[N],b[N],c[N];
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
int ans[1000][1000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int text;
	cin>>text;
	cin>>m>>n>>k>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int ll;
		cin>>ll;
		for(int j=1;j<=ll;j++){
			cin>>b[j]>>c[j];
		}
		for(int j=1;j<=ll;j++)
			for(int k=1;k<=ll;k++)
				if(k!=j)
					add(b[k],b[j],c[j]+c[k]);
		add(b[ll],b[1],c[ll]+c[1]);
		add(b[1],b[ll],c[ll]+c[1]);
	}
	for(int ii=1;ii<=n;ii++){
//		cnt=0;
		for(int i=0;i<=n+1;i++)dis[i]=0x3f3f3f3f3f3f3f,vis[i]=0;
		dis[ii]=0;
		s=ii;
		priority_queue<node>q;
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
		for(int i=1;i<=n;i++){
			ans[ii][i]=dis[i];
		}
	}
	while(T--){
		int end;
		cin>>s>>end;
		cout<<ans[s][end]+a[s]+a[end]<<'\n';
	}
	return 0;
}

