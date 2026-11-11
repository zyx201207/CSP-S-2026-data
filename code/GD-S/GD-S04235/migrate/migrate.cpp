#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
#define int ll
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=1000010;

struct EDGENODE{
	int to;
	int w;
	int nxt;
}edge[N*2];
int head[N],cnt;
void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
	edge[++cnt].to=u;
	edge[cnt].nxt=head[v];
	head[v]=cnt;
}
int h[N],x[N],n,d;
void bfs(int s){
	memset(h,0,sizeof(h));
	queue<pair<int,int> >q;
	h[s]=1;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().second,dep=q.front().first;
		q.pop();
		if(h[u])continue;
		h[u]=dep;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			q.push({dep+1,v});
		}
	}
}
int bfs2(int s,int e){
	int sum=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==e){sum++;break;}
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(h[v]<h[u])q.push(v);
		}
	}
	return sum;
}

void run(){
	memset(head,0,sizeof(head));
	cnt=0;
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			if(abs(x[u]-x[v])<=d)add(u,v);
		}
	}
	
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(bfs2(j,i)==2)ans++;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin>>t>>t;
	while(t--)run();
	return 0;
}

