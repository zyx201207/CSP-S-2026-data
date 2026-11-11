#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,j,k) for(int i=(j);i<=(k);i++)
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}
const int N=510,M=1010,inf=2e18+7;
int c,n,m,w[M],a[N][M],t[N][M],k[N],mx,q,st;
int d[M][M];
bool b[M];
struct node{
	int to,w;
};
vector<node> E[M];
int edge[M][M];

void dijkstra(){
	d[st][st]=0;
	memset(b,0,sizeof(b));
	priority_queue<pair<int,int> > q;
	q.push({0,st});
	while(q.size()){
		int x=q.top().second;q.pop();
		if(b[x]) continue;
		b[x]=1;
		for(node i:E[x]){
			if(b[i.to]) continue;
			if(d[st][i.to]>d[st][x]+i.w){
				d[st][i.to]=d[st][x]+i.w;
				q.push({-d[st][i.to],i.to});
			}
		}
	}
}
void Floyd(){
	For(k,1,m){
		For(i,1,m){
			For(j,1,m){
				edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),mx=read(),q=read();
	bool flag=1;
	For(i,1,m) w[i]=read();
	memset(edge,0x3f,sizeof(edge));
	memset(d,0x3f,sizeof(d));
	For(i,1,n){
		k[i]=read();
		if(k[i]!=2) flag=0;
		For(j,1,k[i]){
			a[i][j]=read(),t[i][j]=read();
			For(l,1,j-1){
				int u=a[i][j],v=a[i][l],z=t[i][j]+t[i][l];
				E[a[i][j]].push_back({a[i][l],z});
				E[a[i][l]].push_back({a[i][j],z});
				edge[u][v]=edge[v][u]=z;
			}
		}
	}
	if(flag){
		For(i,1,m) st=i,dijkstra();
	}
	else{
		Floyd();
	}
	while(q--){
		int u=read(),v=read();
		if(flag) printf("%lld\n",d[u][v]+w[u]+w[v]);
		else printf("%lld\n",edge[u][v]+w[u]+w[v]);
	}
	return 0;
}
