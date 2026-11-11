#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
inline ll readll(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	ll x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
void put(int x){
	if(x>9) put(x/10);
	putchar((x%10)^48);
}
void putll(ll x){
	if(x>9) putll(x/10);
	putchar((x%10)^48);
}
int c,n,m,d,q;
ll dis[N][N];
int w[M];
vector<pii> vec[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1,a,t;j<=k;j++){
			a=read(),t=read();
			vec[a].push_back(make_pair(i,t));
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size()-1;j++){
			for(int k=j+1;k<vec[i].size();k++){
				int u=vec[i][j].first,v=vec[i][k].first;
				ll w=vec[i][j].second+vec[i][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	}
	for(int i=0,x,y;i<q;i++){
		x=read(),y=read();
		//cout<<x<<" and "<<y<<endl;
		ll res=dis[0][0];
		for(pii p:vec[x]) for(pii q:vec[y]) res=min(res,dis[p.first][q.first]+p.second+q.second);
		putll(res+w[x]+w[y]),putchar(10);
	}
	return 0;
}

