#include<bits/stdc++.h>
using namespace std;

const int N=105,INF=1e9;

struct Edge{
	int v,nxt;
};

int n,k,head[N],edge_cnt,ans,stp[N];
Edge edge[N<<1];
bool chs[N];

void Add(int u,int v){
	edge[++edge_cnt]={v,head[u]};
	head[u]=edge_cnt;
	return;
}

int Calc(){
	int e=0;
	for(int u=1;u<=edge_cnt;u++){
		stp[u]=INF;
		if(!chs[u])continue;
		stp[u]=0;
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].v;
			if((!chs[v])||v<u)continue;
			++e;
		}
	}
	if(k-e>2)return INF;
	queue<int> que;
	int res=0;
	for(int u=1;u<=edge_cnt;u++)if(chs[u])que.push(u);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		res=max(res,stp[u]);
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].v;
			if(stp[v]!=INF)continue;
			stp[v]=stp[u]+1;
			que.push(v);
		}
	}
	return res;
}

void GetChs(int u,int cnt){
	if(n-u+1+cnt<k)return;
	if(cnt>k)return;
	if(u>n){
		ans=min(ans,Calc());
		return;
	}
	chs[u]=true;
	GetChs(u+1,cnt+1);
	chs[u]=false;
	GetChs(u+1,cnt);
	return;
}

void Solve(){
	memset(head,-1,sizeof(head));
	edge_cnt=0;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		Add(u,v);
		Add(v,u);
	}
	ans=INF;
	GetChs(1,0);
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)Solve();
	return 0;
}
