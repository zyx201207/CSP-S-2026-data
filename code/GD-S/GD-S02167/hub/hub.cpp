#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;
int c,t,n,k,x,y,ans,b[N],e[N];
vector<int>G[N];
priority_queue<pair<int,int> >q;
int bfs(int c){
	while(!q.empty())q.pop();
	fill(e+1,e+n+1,0);
	q.push({0,c});e[c]=1;
	while(!q.empty()){
		int d=q.top().first,v=q.top().second;q.pop();
		if(b[v]==1)return -d;
		for(auto p:G[v]){
			if(e[p]==0)e[p]=1,q.push({d-1,p});
		}
	}
	return 0;
}
void check(){
	int num=0,maxn=0;
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		for(auto v:G[i])num+=(b[v]==1);
	}
	if(num/2<k-2)return;
	for(int i=1;i<=n;i++)if(!b[i])maxn=max(maxn,bfs(i));
	ans=min(ans,maxn);
}
void solve(int p,int op){
	if(p==k+1){check();return;}
	for(int i=op;i<=n;i++){
		if(b[i]==0){b[i]=1;solve(p+1,i+1);b[i]=0;}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			G[x].push_back(y);G[y].push_back(x);
		}
		ans=n,solve(1,1);
		cout<<ans<<"\n";
	}
	return 0;
}
