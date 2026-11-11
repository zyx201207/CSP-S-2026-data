#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int read(){
	int a=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		a=(a<<3)+(a<<1)+(ch-'0');
		ch=getchar();
	}
	return a*f;
}
inline void write(int a){
	if (a<0){
		a=-a;
		putchar('-');
	}
	if (a>=10) write(a/10);
	putchar(a%10+'0');
}
const int N=5e5+100;
int c,n,m,d,T,x,y,w[N],a[N],t[N],dis[N];
bool vis[N];
struct node{
	int v,w;
};
vector<node> e[N];
typedef pair<int,int> pii;
//priority_queue<pii,vector<pii>,greater<pii>> q;
void dijkstra(int x,int y){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	q.push({0,x});
	dis[x]=0;
	while (q.size()){
		pii h=q.top();
		q.pop();
		int f=h.first,s=h.second;
//		cout<<f<<' '<<s<<' '<<dis[s]<<'\n';
		if (dis[s]<f) continue;
//		vis[s]=true;
		for (node i:e[s]){
//			cout<<i.v<<' '<<i.w<<'\n';
			if (dis[s]+i.w<dis[i.v]){
//				cout<<i.v<<' '<<i.w<<'\n';
				dis[i.v]=dis[s]+i.w;
				q.push({dis[i.v],i.v});
			}
		}
	}
}
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();T=read();
	for (int i=1;i<=m;i++){
		w[i]=read();
	}
	int k;
	for (int i=1;i<=n;i++){
		k=read();
//		memset(a,0,sizeof(a));
//		memset(t,0,sizeof(t));
		for (int j=1;j<=k;j++){
			a[j]=read();t[j]=read();
		}
//		for (int i=1;i<=k;i++){
//			cout<<a[i]<<' '<<t[i]<<'\n';
//		}
		for (int j=1;j<=k;j++){
			for (int l=1;l<=k;l++){
				e[a[j]].push_back({a[l],t[j]+t[l]});
				e[a[l]].push_back({a[j],t[j]+t[l]}); 
			}
		}
	}
	while (T--){
		x=read();y=read();
//		cout<<x<<' '<<y<<'\n';
		dijkstra(x,y);
		write(w[x]+w[y]+dis[y]);putchar('\n');
	}
//	cin>>n>>m>>c;
//	for (int i=1,u,v,w;i<=m;i++){
//		u=read();v=read();w=read();
//		e[u].push_back({v,w});
//		e[v].push_back({u,w});
//	}
//	dijkstra();
//	cout<<dis[c]<<'\n';
	return 0;
}
/*
5 6 3
1 2 1
2 3 2
3 5 5
1 5 2
3 4 2
4 5 1

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
