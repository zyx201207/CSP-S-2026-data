#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=505;
const int M=5e5+5;
const int INF=1e18+5;
int read(){
	int f=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c-'0');
		c=getchar();
	}
	return f*res;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar('0'+x);
	if(x>=10)write(x/10),putchar('0'+(x%10));
}
int c,n,m,d,q,k,x,y,ans;
int dist[N][N];
int w[M];
vector<pii>P[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	for(int i=1;i<=m;i++)
	{
		k=read();
		while(k--){
			x=read(),y=read();
			P[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j)dist[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<P[i].size();j++)
			for(int k=j+1;k<P[i].size();k++)
			{
				int u=P[i][j].first,v=P[i][k].first,w=P[i][j].second+P[i][k].second;
				dist[u][v]=dist[v][u]=min(dist[u][v],w);
			}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		x=read(),y=read();
		ans=INF;
		for(pii it1:P[x])
			for(pii it2:P[y])ans=min(ans,it1.second+it2.second+dist[it1.first][it2.first]);
		write(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
