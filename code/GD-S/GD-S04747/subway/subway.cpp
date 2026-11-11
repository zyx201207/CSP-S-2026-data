#include<bits/stdc++.h>
using namespace std;
int c,n,m,ol,q,x,y,a[500005],k[505];
long long vis[500005],df[505][505],dv[505][505];
vector <int> g[500005],p[505],d[505];
unordered_map <long long,unordered_map <long long,long long> > t;
void solve(){
	queue <int> q;
	q.push(1); 
	vis[1]=1;
	while(!q.empty()){
		int fq=q.front();
		q.pop();
		for(auto i:p[fq]){
			for(int j:g[i]){
				if(j==fq){
					df[fq][j]=0;
					continue;
				}
				if(df[fq][j]==df[fq][0]) d[fq].push_back(j);
				df[fq][j]=min(df[fq][j],t[fq][i]+t[j][i]);
				if(!vis[j]){
					vis[j]=1;
					q.push(j);
				}
			}
		}
	}
}
void find(int X){
	queue <int> q;
	q.push(X);
	dv[X][X]=0;
	vis[X]=1;
	while(!q.empty()){
		int fx=q.front();
		q.pop();
		vis[fx]=0;
		for(auto i:d[fx]){
			if(dv[X][i]>dv[X][fx]+df[fx][i]){
				dv[X][i]=dv[X][fx]+df[fx][i];
				dv[i][X]=dv[X][i];
				if(!vis[i]){
					vis[i]=1;
					q.push(i);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&ol,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		memset(df[i],0x3f,sizeof(df[i]));
		memset(dv[i],0x3f,sizeof(dv[i]));
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&x,&y);
			g[x].push_back(i);
			p[i].push_back(x);
			t[i][x]=y;
		}
	}
	solve();
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		find(i);
	}
	while(q--){
		scanf("%d%d",&x,&y);
		long long minn=1000000000000000005;
		for(auto i:g[x]){
			for(auto j:g[y]){
				minn=min(minn,dv[i][j]+a[x]+a[y]+t[i][x]+t[j][y]);
			}
		}
		printf("%lld\n",minn);
	}
	return 0;
}
