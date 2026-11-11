#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q;
int dis1[4000006],num,dis2[3001][3001],w[500005],dis3[4000006];
int to[8000006],nxt[8000006],val[8000006],h[4000006],cnt;
void add(int a,int b,int c){
	to[++cnt]=b;
	val[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
bool vis[4000006];
void dji1(int s){
	for(int i=1;i<=num;i++)vis[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dis2[s][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(dis2[s][v]>dis2[s][u]+val[i]){
				dis2[s][v]=dis2[s][u]+val[i];
				q.push(make_pair(dis2[s][v],v));
			}
		}
	}
}
void dji2(int s){
	for(int i=1;i<=num;i++)vis[i]=0;
	queue<int>q;
	dis1[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v])continue;
			vis[v]=1;
			dis1[v]=dis1[u]+1;
			q.push(v);
		}
	}
}
void dji3(int s){
	for(int i=1;i<=num;i++)vis[i]=0,dis3[i]=1e18;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dis3[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(dis3[v]>dis3[u]+val[i]){
				dis3[v]=dis3[u]+val[i];
				q.push(make_pair(dis3[v],v));
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	num=m;
	int T=0,bj=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		num++;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(T!=0&&T!=t)bj=0;
			T=t;
			add(a,num,t);
			add(num,a,t);
		}
	}
	if(m<=1000){
		for(int i=1;i<=num;i++)for(int j=1;j<=num;j++)if(i!=j)dis2[i][j]=1e18;
		for(int i=1;i<=m;i++){
			dji1(i);
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+dis2[x][y]<<"\n";
		}
		return 0;
	}
	if(bj){
		while(Q--){
			int x,y;
			cin>>x>>y;
			dji2(x);
			cout<<w[x]+w[y]+dis1[y]*T<<"\n";
		}	
		return 0;
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		dji3(x);
		cout<<w[x]+w[y]+dis3[y]<<"\n";
	}
	return 0;
}
