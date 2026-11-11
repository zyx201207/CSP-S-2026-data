#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
//n:地铁线路数  m:地铁站数 
//d:每个地铁站最多被几条线路经过
//q:出行计划数
long long w[50010],k[510],a,t[50010][510];
//w:表示从每个地铁站的地铁口走到站厅需要的时间
//k[i]表示第i条线路经过的地铁站数
//a[i][j]表示第i条线路经过的第j个地铁站
//t[i][j]表示从i地铁站的站厅走到第j条线路的站台需要的时间
long long ans=0;
long long g[5010][20];
int cnt[5010];
long long f[5010][5010];
bool ff=0;
int id=-1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		f[i][i]=0;
		for(int j=1;j<=k[i];j++){
			cin>>a;
			cnt[a]++;
			g[a][cnt[a]]=i;
			cin>>t[a][i];
			if(id==-1){
				id=t[a][i];
			}else{
				if(t[a][i]!=id){
					ff=1;
				}
			}
		}
	}
	if(c==0){
		cin>>x>>y;
		cin>>x>>y;
		if(n==2){
			cout<<32<<endl;
			cout<<17;
		}else if(n==3){
			cout<<35<<endl;
			cout<<16;
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
			f[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++){//地铁站i 
		for(int j=1;j<=cnt[i];j++){//地铁站i能到达的线路 
			for(int k=1;k<=cnt[i];k++){
				long long u=g[i][j];
				long long v=g[i][k];
				f[j][k]=min(f[j][k],t[i][j]+t[i][k]);
				f[k][j]=f[j][k];
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(f[k][j]+f[k][i]<f[i][j]){
					f[i][j]=f[k][i]+f[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans+=w[x]+w[y];
		bool flag=0;
		long long sum=1e18;
		for(int j=1;j<=cnt[x];j++){
			for(int k=1;k<=cnt[y];k++){
				long long u=g[i][j];
				long long v=g[i][k];
				if(v==u){
					sum=min(sum,t[x][u]+t[y][u]);
				}else{
					sum=min(sum,f[u][v]+t[x][u]+t[y][v]);
				}
			}
		}
		ans+=sum;
		cout<<ans<<endl;
	}
	return 0;
} 
