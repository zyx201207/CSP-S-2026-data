#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int inf=1e18;
//c：测试点 
//n：路线数 
//m：地铁站数 
//d：每个地铁站最多被几条线路经过
//q：询问
const int maxn=505;
const int maxm=5e5+5;
int w[maxm];
#define pii pair<int,int> 
vector<pii> vec[maxm];
int dis[maxn][maxn];

struct IO{
	inline int read(){
		int ans=0,res=1;
		char c=getchar();
		while(c>'9'||c<'0'){
			if(c=='-') res=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			ans=ans*10+c-'0';
			c=getchar();
		}
		return res*ans;
	}
	void write(int x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}io;
inline int min(int a,int b){ return a<b?a:b; }
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=io.read(),n=io.read(),m=io.read(),d=io.read(),q=io.read();
	for(int i=1;i<=m;i++) w[i]=io.read();
	for(int i=1,k;i<=n;i++){
		k=io.read();
		for(int j=1,A,T;j<=k;j++){
			A=io.read(),T=io.read();
			vec[A].push_back({i,T});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int I=1;I<=m;I++){
		int len=(int)vec[I].size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				int u=vec[I][i].first;
				int v=vec[I][j].first;
				int Len=vec[I][i].second+vec[I][j].second;
				dis[u][v]=min(dis[u][v],Len);
				dis[v][u]=min(dis[v][u],Len);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=io.read(),y=io.read();
		int ans=inf;
		for(pii i:vec[x]){
			for(pii j:vec[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		io.write(ans+w[x]+w[y]),putchar('\n');
	}
	return 0;
} 
