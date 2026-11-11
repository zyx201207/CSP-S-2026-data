#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){write(-x); return;}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
vector<pii> sta[M],line[N];
int e[N][N],dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			sta[a].push_back({i,t});
			line[i].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++) sort(sta[i].begin(),sta[i].end());
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j)?0:1e18;
	for(int i=1;i<=n;i++){
		for(auto p:line[i]){
			int u=p.fi,d=p.se;
			for(auto q:sta[u]) dis[i][q.fi]=min(dis[i][q.fi],d+q.se);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x=read(),y=read(),ans=1e18;
		for(auto p:sta[x]){
			for(auto q:sta[y]) ans=min(ans,p.se+dis[p.fi][q.fi]+q.se);
		}
		write(ans+w[x]+w[y]); puts("");
	}
	return 0;
}

