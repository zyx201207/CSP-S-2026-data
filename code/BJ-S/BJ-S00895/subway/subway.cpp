#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define LL __int128
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
inline ll read(){
	ll k=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	if(f)return -k;else return k;
}
inline char readc(){
	char c=getchar();
	while(!isgraph(c))c=getchar();
	return c;
}
inline string reads(){
	string s="";char c=getchar();
	while(!isgraph(c))c=getchar();
	while(isgraph(c)){s+=c;c=getchar();}
	return s;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar((x%10)^48);
	return ;
}
const int N=510;
const int M=5e5+10;
const ll inf=1e18;
ll c,n,m,d,Q,w[M],k[N],dis[M],DIS,pos[M][2],D[N],T;
bool vis[M],mpa[M],mpb[M];
vector<int>a[N],t[N],G[M];
set<int>st[M];
vector<pli>g[M+N];
priority_queue<pli,vector<pli>,greater<pli>>q;
inline int dij(int s,int t){
	for(int i=1;i<=m+n;++i){
		vis[i]=0;
		dis[i]=inf;
	}
	while(q.size())q.pop();
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		auto now=q.top().se;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		if(now==t)return dis[now];
		for(auto i:g[now]){
			if(dis[i.se]>dis[now]+i.fi){
				dis[i.se]=dis[now]+i.fi;
				q.push({dis[i.se],i.se});
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i)w[i]=read();
	int cnt=m;
	for(int i=1;i<=n;++i){
		k[i]=read();
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		++cnt;
		for(int j=1;j<=k[i];++j){
			a[i][j]=read();
			t[i][j]=read();
			if(i==1)mpa[a[i][j]]=1,pos[a[i][j]][1]=j-1;
			else if(i==2)mpb[a[i][j]]=1,pos[a[i][j]][0]=j-1;
			g[cnt].pb({t[i][j],a[i][j]});
			g[a[i][j]].pb({t[i][j],cnt});
			st[a[i][j]].insert(i);
			T=t[i][j];
		}
	}
	if(n==1){
		while(Q--){
			int x=read(),y=read();
			printf("%lld\n",w[x]+w[y]+g[x][0].fi+g[y][0].fi);
		}
		return 0;
	}
	if(n==2)DIS=dij(m+1,m+2);
	if(16<=c&&c<=19){
		for(int i=1;i<=m;++i){
			for(auto j:st[i]){
				if(j==*st[i].begin())continue;
				auto k=st[i].begin();
				while(j!=(*k)){
					G[j].pb(*k);;
					G[*k].pb(j);
					++k;
				}
			}
		}
	}
	while(Q--){
		int x=read(),y=read();
		if(c<=15)printf("%lld\n",dij(x,y)+w[x]+w[y]);
		else if(c<=19){
			ll ans=w[x]+w[y];
			while(q.size())q.pop();
			for(int i=1;i<=n;++i)D[i]=1e18,vis[i]=0;
			for(auto i:st[x])q.push({0,i}),D[i]=0;
			while(q.size()){
				int now=q.top().se;
				q.pop();
				if(vis[now])continue;
				vis[now]=1;
				if(st[y].find(now)!=st[y].end()){
					ans+=T*2*(D[y]+1);
					break;
				}
				for(int i:G[now]){
					if(D[i]>D[now]+1){
						D[i]=D[now]+1;
						q.push({D[i],i});
					}
				}
			}
			printf("%lld\n",ans);
		}
		else if(c<=21){
			ll ans;
			if(mpa[x]&&mpa[y]&&!mpb[x]&&!mpb[y])ans=g[m+1][pos[x][1]].fi+g[m+1][pos[y][1]].fi;
			else if(!mpa[x]&&!mpa[y]&&mpb[x]&&mpb[y])ans=g[m+2][pos[x][0]].fi+g[m+2][pos[y][0]].fi;
			else if(mpa[x]&&!mpb[x]&&mpa[y]&&mpb[y]){
				ans=g[m+1][pos[x][1]].fi+min(g[m+1][pos[y][1]].fi,DIS+g[m+2][pos[y][0]].fi);
			}
			else if(mpa[y]&&!mpb[y]&&mpa[x]&&mpb[x]){
				ans=g[m+1][pos[y][1]].fi+min(g[m+1][pos[x][1]].fi,DIS+g[m+2][pos[x][0]].fi);
			}
			else if(!mpa[x]&&mpb[x]&&mpa[y]&&mpb[y]){
				ans=g[m+2][pos[x][0]].fi+min(g[m+2][pos[y][0]].fi,DIS+g[m+1][pos[y][1]].fi);
			}
			else if(!mpa[y]&&mpb[y]&&mpa[x]&&mpb[x]){
				ans=g[m+2][pos[y][0]].fi+min(g[m+2][pos[x][0]].fi,DIS+g[m+1][pos[x][1]].fi);
			}
			else if(mpa[x]&&!mpb[x]&&!mpa[y]&&mpb[y])ans=DIS+g[m+1][pos[x][1]].fi+g[m+2][pos[y][0]].fi;
			else if(!mpa[x]&&mpb[x]&&mpa[y]&&!mpb[y])ans=DIS+g[m+2][pos[x][0]].fi+g[m+1][pos[y][1]].fi;
			else{
				ans=max({g[m+1][pos[x][1]].fi+g[m+1][pos[y][1]].fi,g[m+2][pos[x][0]].fi+g[m+2][pos[y][0]].fi,
					     g[m+1][pos[x][1]].fi+g[m+2][pos[y][0]].fi+DIS,g[m+2][pos[x][0]].fi+g[m+1][pos[x][1]].fi+DIS});
			}
			printf("%lld\n",w[x]+w[y]+ans);
		}
		
	}
	return 0;
}
