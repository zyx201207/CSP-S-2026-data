#include<bits/stdc++.h>
using namespace std;
#define N 505
#define M 500005
typedef long long ll;
inline ll read(){
	register ll x=0,f=1ll;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3ll)+(x<<1ll)+(ch^48);ch=getchar();}
	return x*f;
}
int c,n,m,d,q;
ll w[M],dis[N][N];
int t[N][M];
vector<int> v[M];
inline void add(int i,int j,int k){//从线路i换乘到线路j，换乘点为k
	dis[i][j]=min(dis[i][j],1ll*t[i][k]+1ll*t[j][k]);
}
inline ll query(int x,int y){
	ll ans=2e18;
	for(int i:v[x])
		for(int j:v[y])ans=min(ans,(ll)dis[i][j]+1ll*t[i][x]+1ll*t[j][y]);
	return ans+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			int u=read();t[i][u]=read();
			v[u].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if (i==j)dis[i][j]=0;
			else dis[i][j]=2e18;
		}
	for(int i=1;i<=m;i++){
		if (v[i].size()>=2){
			for(int j=0;j<v[i].size();j++)
				for(int k=0;k<v[i].size();k++)
					if (j!=k)add(v[i][j],v[i][k],i);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	while(q--){
		int u=read(),v=read();
		cout<<query(u,v)<<'\n';
	}
	return 0;
}
