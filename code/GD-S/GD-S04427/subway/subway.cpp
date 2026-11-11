#include<bits/stdc++.h> 
using namespace std;
const int M=5e5+10,N=510;
int w[M];
int read(){
	int res=0,sig=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')sig=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res*=10;
		res+=c-'0';
		c=getchar();
	}
	return res*sig;
}
int c,n,m,d,q;
vector<vector<int> >a(N,vector<int>(M)),t(N,vector<int>(M));  
vector<vector<pair<int,int> > >rec(M,vector<pair<int,int> >());
int k[N];
long long dij(int st,int ed){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,st});
	vector<long long> dis(m+1),vis(m+1);
	for(int i=1;i<=m;++i){
		dis[i]=1e18;
	}dis[st]=0;
	while(!pq.empty()){
		int cur=pq.top().second,len=pq.top().first;
		pq.pop();
		vis[cur]=1;
		for(auto tmp:rec[cur]){
			int line=tmp.first,id=tmp.second;
			int tc=t[line][id];
			for(int i=1;i<=k[line];i++){
				int nxt=a[line][i];
				if(nxt==cur||vis[nxt])continue;
				int tn=t[line][i];
				if(dis[cur]+tc+tn<dis[nxt]){
					dis[nxt]=dis[cur]+tc+tn;
					pq.push({dis[nxt],nxt});
				}
			}
		}
	}
	return dis[ed];
}
void solve(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	//scanf("%d %d %d %d %d\n",&c,&n,&m,&d,&q);
	//cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		w[i]=read();
		//scanf("%d ",&w[i]);
		rec[i].reserve(d+1);
	}
	for(int i=1;i<=n;++i){
		k[i]=read();
//		scanf("%d ",&k[i]);
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
//			scanf("%d ",&a[i][j]);
			rec[a[i][j]].push_back({i,j});
			t[i][j]=read();
//			scanf("%d ",&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		x=read(),y=read();
//		scanf("%d %d",&x,&y);
//		cout<<dij(x,y)+w[x]+w[y]<<"\n";
		printf("%lld\n",dij(x,y)+w[x]+w[y]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
