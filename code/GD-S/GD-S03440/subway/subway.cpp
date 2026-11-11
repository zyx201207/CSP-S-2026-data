#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define mp(x,y) make_pair(x,y)
const int N=510,M=500010;
const ll INF=900000000000000000;

int c,n,m,d,q;
int w[M];
vector<PII> g[M];
ll link[N][N];
ll ans;

ll read(){
	ll x=0;char c;
	while(c=getchar()){
		if(c==' '||c=='\n') break;
		x+=c-'0';x*=10;
	}
	x/=10;
	return x;
}


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		int k,x,y;
		k=read();
		for(int j=1;j<=k;j++){
			x=read();y=read();
			g[x].push_back(mp(i,y));
		}
		for(int j=1;j<=n;j++){
			link[i][j]=INF;
		}
		link[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int x=g[i][j].first,y=g[i][k].first;
				link[y][x]=link[x][y]=min(link[x][y],1ll*(g[i][j].second+g[i][k].second));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==i||k==j) continue;
				link[j][i]=link[i][j]=min(link[i][j],link[i][k]+link[k][j]);
			}
		}
	}
	while(q--){
		ans=INF;
		int x1,y1;
		x1=read();y1=read();
		for(int j=0;j<g[x1].size();j++){
			for(int k=0;k<g[y1].size();k++){
				int x=g[x1][j].first,y=g[y1][k].first;
				ll sum=g[x1][j].second+g[y1][k].second+link[x][y];
				ans=min(ans,sum);
			}
		}
		ans+=w[x1]+w[y1];
		cout<<ans<<'\n';
	}
	
	
	
	return 0;
}
