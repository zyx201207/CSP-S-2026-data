#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005],akcsp[50005],ans;
int a[505][50005],t[505][50005];
int nex[505][50005];
int dis[500005],vis[500005];
struct node{
	int w,to,nxt,xl;
}s[100005];
int head[10005],cnt,che[10005];
void add(int u,int v,int e){
	s[++cnt].to=v;
	s[cnt].nxt=head[u];
	s[cnt].w=e;
	//s[cnt].xl=o;
	head[u]=cnt;
	//che[head[o*u]]=o;
}
priority_queue< pair<int,int> >que;
void dij(int l){
	for(int i=1;i<=n*m;++i)dis[i]=1e9;
	memset(vis,0,sizeof vis);
	dis[l]=0;
	que.push(make_pair(0,l));
	while(!que.empty()){
		int u=que.top().second;
		que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u],v;i;i=s[i].nxt){
			//if(u==3)cout << head[u] << ' ' << che[head[u]] << '\n';
			v=s[i].to;
			//if(che[head[s[i].xl*u]]!=s[i].xl)continue;
			if(dis[v]>dis[u]+s[i].w){
				dis[v]=dis[u]+s[i].w;
				//cout << u << ' ' << v << ' ' << s[i].w << '\n';
				if(!vis[v])que.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i){
		cin >> w[i];
	}
	for(int j=1,k;j<=n;++j){
		cin >> k;
		for(int i=1;i<=k;++i){
			cin >> a[j][i];
			akcsp[a[j][i]]++;
			a[j][i]=a[j][i]+(j-1)*m;
			cin >> t[j][a[j][i]];
		}
		for(int i=2;i<=k;++i){
			add(a[j][i-1],a[j][i],t[j][a[j][i-1]]);
			//cout << a[j][i-1] << ' ' << a[j][i] << ' ' << t[j][a[j][i-1]] << ' ' << j << '\n';
		}
	}
	for(int i=1;i<=m;++i){
		if(akcsp[i]>1){
			for(int j=1;j<=akcsp[i];++j){
				for(int k=1;k<=akcsp[i];++k){
					if(k==j)continue;
					add(a[j][i],a[j][i]+(k-1)*m,t[k][a[j][i]+(k-1)*m]+t[j][a[j][i]]);
					//cout << a[j][i] << ' ' << a[j][i]+(k-1)*m << ' ' << t[k][a[j][i]+(k-1)*m]+t[j][a[j][i]] << '\n';
				}
			}
		}
	}
	for(int i=1;i<=cnt;++i){
		//cout << che[i] << ' ';
		//cout << s[i].w << ' ' << s[i].to << ' ' << s[i].nxt << ' ' << s[i].xl << '\n';
	}
	for(int i=1,x,y;i<=q;++i){
		cin >> x >> y;
		ans=1e9+1;
		dij(x);
		for(int j=0;j<n;++j)ans=min(ans,dis[y*2+j*m*2]);
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
}

