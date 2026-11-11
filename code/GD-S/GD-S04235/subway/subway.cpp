#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
#define int ll
#define endl '\n'
#define gc getchar
typedef long long ll;
using namespace std;
const int N=1000010;

int c;
struct EDGENODE{
	int to;
	int w;
	int nxt;
}edge[N*2];
int head[N],cnt;
void add(int u,int v,int w){
	//cout<<"add:"<<u<<"-->"<<v<<endl;
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int dist[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
void dijstra(int s){
	//cout<<"dij:start at"<<s<<endl;
	memset(dist,0x3f,sizeof(dist));
	while(!pq.empty())pq.pop();
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second,w=pq.top().first;
		pq.pop();
		if(w>dist[u])continue;
		dist[u]=w;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dist[v]>dist[u]+edge[i].w){
				//cout<<u<<"--"<<w<<"-->"<<v<<endl;
				dist[v]=dist[u]+edge[i].w;
				pq.push({dist[v],v});
			}
		}
	}
}
vector<pair<int,int> >qu[N];
int n,m,d,q,ou[N],num[N],ans[N];
void get1(){
	//小数据：dijstra暴力 
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		while(k--){
			cin>>a>>t;
			num[a]++;
			add(i,(n+(d+1)*(a-1)+1)+num[a],0);
			add((n+(d+1)*(a-1)+1)+num[a],i,0);
			add((n+(d+1)*(a-1)+1)+num[a],n+(d+1)*(a-1)+1,t);
			add(n+(d+1)*(a-1)+1,(n+(d+1)*(a-1)+1)+num[a],t);
		}
	}
	
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		if(s>e)swap(s,e);
		qu[s].push_back({e,i});
	}
	
	for(int s=1;s<=m;s++){
		if(qu[s].empty())continue;
		dijstra(n+(d+1)*(s-1)+1);
		for(auto p:qu[s]){
			int e=p.first;
			ans[p.second]=dist[n+(d+1)*(e-1)+1]+ou[s]+ou[e];
		}
	}
	
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
}

void get2(){
	//特殊性质B：车站只需拆成两个点 
	int t;
	for(int i=1;i<=n;i++){
		int k,a;
		cin>>k;
		while(k--){
			cin>>a>>t;
			add(i,n+a,0);
			add(n+m+a,i,0);
		}
	}
	for(int i=1;i<=m;i++){
		add(n+i,n+m+i,2*t);
	}
	
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		if(s>e)swap(s,e);
		qu[s].push_back({e,i});
	}
	for(int s=1;s<=m;s++){
		if(qu[s].empty())continue;
		dijstra(n+m+s);
		for(auto p:qu[s]){
			int e=p.first;
			ans[p.second]=dist[n+e]+ou[s]+ou[e];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
}
int chg[N];
void get3(){
	//n=2：找换乘站
	int way=inf;
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		while(k--){
			cin>>a>>t;
			chg[a]=i;
			if(!num[a])num[a]=t;
			else way=min(way,num[a]+t),chg[a]=3;
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		if(chg[s]==3||chg[e]==3||chg[s]==chg[e])cout<<ou[s]+ou[e]<<endl;
		else cout<<ou[s]+ou[e]+way<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ou[i];
	if(n==1){
		for(int i=1;i<=m;i++){
			cin>>ou[i];
		}
		int h;
		for(int i=1;i<=n;i++)cin>>h>>h>>h;
		for(int i=1;i<=q;i++){
			int s,e;
			cin>>s>>e;
			cout<<ou[s]+ou[e]<<endl;
		}
	}
	else if(c<=15)get1();
	else if(c>=15&&c<=19)get2();
	else if(c>=20&&c<=21)get3();
	else get1();
	return 0;
}

