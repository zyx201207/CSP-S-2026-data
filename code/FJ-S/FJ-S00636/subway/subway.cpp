#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e4+5,M=2e3+5;
int c,n,m,d,qq;
struct node{
	int v,w,nxt;
}e[N<<1];
int h[N<<1],idx;
void add(int u,int v,int w){
	e[++idx]={v,w,h[u]};
	h[u]=idx;
}
int a[N];
int dist[M][M],vs[M][M];
priority_queue<pair<int,int> >q;
void dj(int s){
	q.push({0,s});
	dist[s][s]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vs[s][u])continue;
		vs[s][u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dist[s][v]>dist[s][u]+w){
				dist[s][v]=dist[s][u]+w;
				q.push({-dist[s][v],v});
			}
		}
	}
}
int dst[N],vss[N];
int dl[N],lt,rt;
int djj(int s,int t){
	memset(dst,0,sizeof(dst));
	memset(vss,0,sizeof(vss));
	lt=1,rt=0;
	dl[++rt]=s;
	vss[s]=1;
	while(lt<=rt){
		int u=dl[lt];
		lt++;
		if(u==t){
			return dst[t];
		}
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(vss[v]==1)continue;
			dst[v]=dst[u]+w;
			dl[++rt]=v;
			vss[v]=1;
		}
	}
}
int aa[500005],vv[500005],w[500005][2],mn;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin >> c >> n >> m >> d >> qq;
	if(c<=11){
		for(int i=1;i<=m;i++)cin >> a[i];
		for(int i=1;i<=n;i++){
			int k;cin >> k;
			for(int j=1;j<=k;j++){
				int x,w;cin >> x >> w;
				add(m+i,x,w),add(x,m+i,w);
			}
		}
		memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=m;i++){
			dj(i);
		}
		while(qq--){
			int x,y;cin >> x >> y;
			cout << dist[x][y]+a[x]+a[y] << '\n';
		}
		return 0;
	}
	if(12<=c&&c<=15){
		for(int i=1;i<=m;i++)cin >> a[i];
		for(int i=1;i<=n;++i){
			int k;cin >> k;
			for(int j=1;j<=k;++j){
				int x,w;cin >> x >> w;
				add(m+i,x,w),add(x,m+i,w);
			}
		}
		while(qq--){
			int x,y;cin >> x >> y;
			cout << djj(x,y)+a[x]+a[y] << '\n';
		}
		return 0;
	}
	if(20==c||21==c){
		for(int i=1;i<=m;i++)cin >> aa[i];
		for(int i=1;i<=n;i++){
			int k;cin >> k;
			for(int j=1;j<=k;j++){
				int x,ww;cin >> x >> ww;
				vv[x]+=i;w[x][i-1]=ww;
			}
		}
		mn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++){
			if(vv[i]==3)mn=min(mn,w[i][0]+w[i][1]);
		}
		while(qq--){
			int x,y;cin >> x >> y;
			if(n==1){
				cout << aa[x]+aa[y]+w[x][0]+w[y][0];
				continue;
			}
			int ans=0x3f3f3f3f3f3f3f3f;
			if(vv[x]%2==1&&vv[y]%2==1)ans=min(w[x][0]+w[y][0],ans);
			if(vv[x]>=2&&vv[y]>=2)ans=min(ans,w[x][1]+w[y][1]);
			if(vv[x]>=2&&vv[y]%2==1&&mn!=0x3f3f3f3f3f3f3f3f)ans=min(ans,w[x][1]+w[y][0]+mn);
			if(vv[y]>=2&&vv[x]%2==1&&mn!=0x3f3f3f3f3f3f3f3f)ans=min(ans,w[y][1]+w[x][0]+mn);
			cout << ans+aa[x]+aa[y] << '\n';
		}
		return 0;
	}
	return 0;
}
