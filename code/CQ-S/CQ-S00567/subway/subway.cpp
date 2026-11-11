#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edg{
	int t,w;
};
char buf[100000000];
vector<edg> grp[500010];
ll dis[510][510];
int th[500010];
int c,n,m,d,q;
int u,v,w;
int bufp;
int read(){
	while(!isdigit(buf[bufp])) bufp++;
	int res=0;
	while(isdigit(buf[bufp])){
		res=res*10+buf[bufp]-'0';
		bufp++;
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fread(buf,1,100000000,stdin);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) th[i]=read();
	for(int i=1;i<=n;i++){
		w=read();
		while(w--){
			u=read();
			v=read();
			grp[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(edg j:grp[i]){
			for(edg k:grp[i]) dis[j.t][k.t]=min(dis[j.t][k.t],(ll)j.w+k.w);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		u=read();
		v=read();
		ll ans=1e18;
		for(edg j:grp[u]){
			for(edg k:grp[v]) ans=min(ans,dis[j.t][k.t]+j.w+k.w+th[u]+th[v]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
15:21 start
15:34 test
15:36 pass,write fread
15:41 check
15:47 finish
*/
