#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,P=21;
const long long INF=1e18;
long long c,n,m,d,q,w[M],cnt[M],t[M][P],mt[M][P],id[M][P],dis[N][N];
vector<int> a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k; cin>>k;
		for(int j=1;j<=k;j++){
			long long x,y; cin>>x>>y;
			a[i].push_back(x);
			id[x][++cnt[x]]=i;
			t[x][cnt[x]]=mt[x][i]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			long long u=a[i][j],s=mt[u][i];
			for(int k=1;k<=cnt[u];k++){
				long long v=id[u][k],w=t[u][k];
				if(u==v) continue;
				dis[i][v]=dis[v][i]=min(dis[i][v],s+w);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		long long x,y,res=INF,resx,resy; cin>>x>>y;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++)
				if(res>dis[id[x][i]][id[y][j]])
					res=dis[id[x][i]][id[y][j]],resx=id[x][i],resy=id[y][j];
		cout<<res+w[x]+w[y]+mt[x][resx]+mt[y][resy]<<'\n';
	}
	return 0;
}
/*
O(n^3+dm+d^2q)=1.25e8+1e7+4e7=1.75e8=CCF少爷机 
luogu:UID 1011277,昵称：xiaoxiaozhang_123
在考场门口穿不明黄色生物衣服并大声声张我是萘珑的神人是
bilibili昵称：一只小小弓长
大概率会在考试结束后发视频（？） 
*/
