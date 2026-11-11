#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],dis[5010],cnt[5010],ans;

struct E{
	int v,w;
};
vector<E> G[5010];

void bfs(int st){
	queue<int> q;
	q.push(st);
	for(int i=st;i<=n;i++){
		dis[i]=1e18;
		cnt[i]=0;
	}
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v;
			int w=G[u][i].w;
			if(v<=u) continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]=1;
				q.push(v);
			}
			else if(dis[v]==dis[u]+w){
				cnt[v]++;
//				q.push(v);
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=5000){
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++) while(G[i].size()) G[i].pop_back();
			int l=1,r=1;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]<=x[i]+d) G[i].push_back({j,1});
					else{
	//					cout<<x[i]<<" "<<x[j]<<"\n";
	//					cout<<i<<"和"<<j<<"的差为"<<x[j]-x[i]<<"大于"<<d<<"\n";
						break;
					}
				}
			}
			for(int i=1;i<=n;i++){
				bfs(i);
				for(int j=i+1;j<=n;j++){
					if(cnt[j]==2) ans++;
	//				cout<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n";
				} 
	//			cout<<"\n";
			}
			cout<<ans<<"\n";
		}
		else cout<<"0";
	}
	return 0;
}
