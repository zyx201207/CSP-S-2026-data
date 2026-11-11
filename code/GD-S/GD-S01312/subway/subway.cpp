#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q;
int w[500005];
int f[505][505];
struct o{
	int x,w;
};
vector<o> g[500005];
inline int work(int st,int ed){
	int l1=g[st].size();
	int l2=g[ed].size();
	int cnt=w[st]+w[ed];
	int ans=1e18;
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			int x=g[st][i].x,y=g[ed][j].x;
			int wx=g[st][i].w,wy=g[ed][j].w;
			ans=min(ans,f[x][y]+wx+wy);
		}
	}return ans+cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=1e18;
		}
	}for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}for(int i=1;i<=m;i++){
		int len=g[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int x=g[i][j].x,y=g[i][k].x;
				f[x][y]=min(f[x][y],g[i][j].w+g[i][k].w);
				f[y][x]=min(f[y][x],g[i][j].w+g[i][k].w);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==k||i==j||j==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<work(st,ed)<<endl;
	}
	return 0;
}
