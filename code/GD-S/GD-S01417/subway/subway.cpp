#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=ll>T read(T&&x=T()){
	x=0;int fg=1;
	char c=gc();
	while(!isdigit(c))
		fg-=(c=='-')<<1,c=gc();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=gc();
	return x*=fg;
}
const int M=5e5+600,N=505;
vector<pair<ll,int>>p[M];
int w[M],k[N];
ll len[N][N],dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int i=1;i<=n;i++){
		read(k[i]);
		for(int j=1;j<=k[i];j++){
			int a=read(),t=read();
			p[a].push_back(make_pair(t,i));
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			for(int k=0;k<j;k++){
				int u=p[i][j].second,v=p[i][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],p[i][j].first+p[i][k].first);
			}
		}
	}
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x=read(),y=read();
		ll ans=1e18;
		for(pair<ll,int>u:p[x])for(pair<ll,int>v:p[y]){
			ans=min(ans,dis[u.second][v.second]+u.first+v.first);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}