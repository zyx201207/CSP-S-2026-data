#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::string;

const int K=5e5;
const int N=5e6;

int c,m,n,d,q;
int s[N],t[N],k[N];
int cnt,to[K],head[N],pth[K],nxt[K],maxx;
void addedge(int u,int v,int w){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	pth[cnt]=w;
	head[u]=cnt;
}

int dis[N],flg[N];

int* Dijkstra(int start){
	memset(dis,0x3f3f3f,sizeof(dis));
	memset(flg,0,sizeof(flg));
	dis[start]=0;
	while(1){
		int u=0;
		for(int i=1;i<=maxx;i++){
			if(!flg[i]&&dis[i]<dis[u]) u=i;
		}
		if(u==0) break;
		flg[u]=1;
		
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=pth[i];
			if(!flg[v]&&dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
			}
		}
	}
	return dis;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1,a;i<=m;i++){
		cin>>a;
		addedge(i,i+m,a);
		addedge(i+m,i,a);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s[j]>>t[j];
			if(j>1){
				addedge(s[j]+(i+1)*m,s[j-1]+(i+1)*m,0);
				addedge(s[j-1]+(i+1)*m,s[j]+(i+1)*m,0);
			}
			addedge(s[j]+m,s[j]+(i+1)*m,t[j]);
			addedge(s[j]+(i+1)*m,s[j]+m,t[j]);
			
			maxx=std::max(maxx,s[j]+(i+1)*m);
		}
	}
//	for(int u=1;u<=maxx;u++){
//		cout<<u<<": ";
//		for(int i=head[u];i;i=nxt[i]){
//			cout<<"("<<to[i]<<","<<pth[i]<<") ";
//		}
//		cout<<endl;
//	} 
	for(int i=1,l,r;i<=q;i++){
		cin>>l>>r;
		
		cout<<Dijkstra(l)[r]<<endl;
		
//		cout<<dis[r]<<endl;
		
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


0 2 5 20 1
1 1 1 1 1
3 1 1 2 1 3 1
3 3 1 4 1 5 1
1 5
*/
