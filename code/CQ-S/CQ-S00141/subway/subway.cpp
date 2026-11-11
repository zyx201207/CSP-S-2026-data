//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//inline int read(){
//	int ret=0;bool sgn=false;char ch=getchar();
//	while((ch<'0'||ch>'9')&&(ch!='-'))ch=getchar();
//	if(ch=='-')sgn=false,ch=getchar();
//	while('0'<=ch&&ch<='9')ret*=10,ret+=ch-'0',ch=getchar();
//	return sgn?ret:-ret;
//}
//const int N=1e6+5;
//const int S=505; 
//const int D=25;
//const int inf=0x7f7f7f7f7f7f7f7f;
//int d[N];
//int vis[N];
//struct node{
//	int v,w;
//	node(){}
//	node(int _v,int _w):v(_v),w(_w){}
//	friend bool operator<(const node&__x,const node&__y){return __x.w<__y.w;}
//	friend bool operator>(const node&__x,const node&__y){return __x.w>__y.w;}
//};
//vector<int>a[N];
//int dis[S][S];
//int w[N];
//int n,m;
//int _d,q;
//vector<node>p[N];
//void floyd(){
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(dis[i][k]==inf||dis[k][j]==inf)continue;
//				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//			}
//		}
//	}
//}
//signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);cin.tie(0);
//	cin>>n>>n>>m>>_d>>q;
//	for(int i=1;i<=m;i++)cin>>w[i];
//	for(int i=1;i<=n;i++){
//		int k;cin>>k;
//		for(int j=0;j<k;j++){
//			int x,y;
//			cin>>x>>y;
//			p[x].push_back(node(i,y));
//		}
//	}
//	memset(dis,0x7f,sizeof dis);
//	for(int i=1;i<=n;i++)dis[i][i]=0;
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<(int)p[i].size();j++){
//			for(int k=0;k<(int)p[i].size();k++){
//				if(j==k)continue;
//				dis[p[i][j].v][p[i][k].v]=min(dis[p[i][j].v][p[i][k].v],p[i][j].w+p[i][k].w);
//			}
//		}
//	}
//	floyd();
//	while(q--){
//		int x,y;
//		cin>>x>>y;
//		int minn=inf;
//		for(int i=0;i<(int)p[x].size();i++){
//			for(int j=0;j<(int)p[y].size();j++){
//				minn=min(minn,dis[p[x][i].v][p[y][j].v]+p[x][i].w+p[y][j].w);
//			}
//		}
//		cout<<minn+w[x]+w[y]<<"\n";
//	}
//	return 0;
//}
///*
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ret*=10,ret+=ch-'0',ch=getchar();
	return ret;
}
const int N=1e6+5;
const int S=505; 
const int D=25;
const int inf=0x7f7f7f7f7f7f7f7f;
int d[N];
int vis[N];
struct node{
	int v,w;
	node(){}
	node(int _v,int _w):v(_v),w(_w){}
	friend bool operator<(const node&__x,const node&__y){return __x.w<__y.w;}
	friend bool operator>(const node&__x,const node&__y){return __x.w>__y.w;}
};
vector<int>a[N];
int dis[S][S];
int w[N];
int n,m;
int _d,q;
vector<node>p[N];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]==inf||dis[k][j]==inf)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>n>>m>>_d>>q;
//	read();n=read();m=read();_d=read();q=read();
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
//		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
//			x=read(),y=read();
			p[x].push_back(node(i,y));
		}
	}
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)p[i].size();j++){
			for(int k=0;k<(int)p[i].size();k++){
				if(j==k)continue;
				dis[p[i][j].v][p[i][k].v]=min(dis[p[i][j].v][p[i][k].v],p[i][j].w+p[i][k].w);
			}
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
//		x=read(),y=read();
		int minn=inf;
		for(int i=0;i<(int)p[x].size();i++){
			for(int j=0;j<(int)p[y].size();j++){
				minn=min(minn,dis[p[x][i].v][p[y][j].v]+p[x][i].w+p[y][j].w);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
		//printf("%lld\n",minn+w[x]+w[y]);
		//write(minn+w[x]+w[y]);putchar('\n');
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
