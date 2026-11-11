#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,Q,num=1,x,y;
int ww[505][N],yy[505][N],k[N];
long long t1[N],head[N*4],dist[N],book[N];
struct node{
	long long nxt,to;
	int w;
}e[N*4];
priority_queue<pair<long long,long long> >  q;
void add(long long x,long long y,int w){
	e[num]={head[x],y,w};
	head[x]=num++;
}
void dis(long long s){
	memset(dist,0x3f,sizeof(dist));
	memset(book,0,sizeof(book));
	dist[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		long long u=q.top().second;
		q.pop();
		if(book[u]) continue;
		book[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			long long v=e[i].to;
			if(dist[v]>dist[u]+e[i].w){
				dist[v]=dist[u]+e[i].w;
				q.push(make_pair(-dist[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>t1[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>yy[i][j]>>ww[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int p=1;p<=k[i];p++){
				for(int o=1;o<=k[j];o++){
					if(yy[i][p]==yy[j][o]){
						add(i,j,ww[i][p]+ww[j][o]);
						add(j,i,ww[i][p]+ww[j][o]);
					}
				}
			}
		}
		
	}
	while(Q--){
		cin>>x>>y;
		dis(x);
		cout<<dis[y]+t1[x]+t1[y]<<endl; 
	}
	//0 2 5 2 0 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
	return 0;
}
