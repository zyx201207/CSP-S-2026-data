#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
vector<int> g[N];int a[N],dist[N],cnt[N];

void bfs(int st,int n){
	queue<int> q;
	q.push(st);
	for(int i=1;i<=n;i++) dist[i]=LONG_LONG_MAX;
	dist[st]=0;
	while(q.size()){
		int u=q.front(); q.pop();
		for(auto v:g[u]){
			q.push(v);
			if(dist[v]==dist[u]+1) cnt[v]++;
			else if(dist[v]>dist[u]+1) cnt[v]=1,dist[v]=dist[u]+1;
		}
	}
	return ;
}

void sol(){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) g[i].push_back(j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<"i="<<i<<"... ";
		for(int j=1;j<=n;j++) cnt[j]=dist[j]=0;
		bfs(i,n);
		//for(int j=1;j<=n;j++) cout<<dist[j]<<' ';
		cout<<endl;
		for(int j=i;j<=n;j++) {
			//cout<<cnt[j]<<' ';
			
			if(cnt[j]==2) ans++;
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		sol();
	}
	return 0;
}
