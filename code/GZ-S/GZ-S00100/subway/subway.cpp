//刘科 GZ-S00100 安顺市第二高级中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=1009;
int n,m,c,d,p;
int dp[kMaxN][kMaxN];
int ari[kMaxN][kMaxN];
int timme[kMaxN][kMaxN];
int end[kMaxN];
struct V{
	vector<int>e;
}v[kMaxN];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;//示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=1;i<=m;i++){
		cin>>end[i];
	}
	for(int i=1;i<=n;i++){
		int le;
		int x=read();
		for(int j=1;j<=x;j++){
			int e,f;
			e=read();f=read();
			ari[i][e]=1;
			timme[i][j]=f;
			if(j!=1){
				v[le].e.push_back(e);
				v[e].e.push_back(le);
			}
			le=e;
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		queue<int>q;
		q.push(x);
		fill(dp[0],dp[n+2],INT_MAX);
		for(int j=1;j<=n;j++){
			dp[j][x]=end[x];
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int j=0;j<v[u].e.size();j++){
				int mu=v[u].e[j];
				for(int z=1;z<=n;z++){
					for(int me=1;me<=n;me++){
						if(dp[me][u]!=INT_MAX&&ari[z][mu]){
							if(me==z){
							dp[z][mu]=min(dp[me][u],dp[z][mu]);
							q.push(mu);
							}else{
							dp[z][mu]=min(dp[me][u]+timme[me][u]+timme[z][u],dp[z][mu]);
							q.push(mu);
							}
						}
					}
				}
			}
		}
		int ans=INT_MAX;
		for(int j=1;j<=n;j++){
			ans=min(ans,dp[j][y]);
		}
		cout<<ans+end[y]<<'\n';
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
