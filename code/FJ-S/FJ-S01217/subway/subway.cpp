#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=1e6+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int c,n,m,d,q,w[N],f[1000][1000];
vector<pair<int,int>>g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j]=INF;
		}
	}
	for(int u=1;u<=n;u++){
		for(pair<int,int> e1:g[u+m]){
			int v1=e1.first,w1=e1.second;
			for(pair<int,int> e2:g[v1]){
				int v2=e2.first-m,w2=e2.second;
				if(v2==u)continue;
				f[u][v2]=min(f[u][v2],w1+w2);
				f[v2][u]=min(f[v2][u],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(f[i][k]==INF)continue;
			for(int j=1;j<=n;j++){
				if(f[j][k]==INF)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//				cout<<i<<" "<<j<<" "<<k<<"\n"<<f[i][j]<<" "<<f[i][k]<<" "<<f[k][j]<<"\n";
//				cout<<f[i][k]+f[k][j]<<"\n";
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<"->"<<j<<" "<<f[i][j]<<"\n";
//		}
//	}
//	for(int i=1;i<=m;i++){
//		for(pair<int,int> e:g[i]){
//			int j=e.first,k=e.second;
//			cout<<i<<"->"<<j<<" "<<k<<"\n";
//		}
//	}
	while(q--){
		int xr=read(),yr=read(),ans=INF;
		for(pair<int,int> e1:g[xr]){
			for(pair<int,int> e2:g[yr]){
				int v1=e1.first-m,w1=e1.second,v2=e2.first-m,w2=e2.second;
				ans=min(ans,f[v1][v2]+w1+w2);
			}
		}
		write(ans+w[xr]+w[yr]),putchar('\n');
	}
	return 0;
}
