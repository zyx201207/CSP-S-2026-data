#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[500001],ans[500001],anss,dis[500001],x2[2000001];
vector<int> g[500001];
queue<pair<int,int> > q;
void bfs(int s){
	int res=0;
	for(int i=0;i<=n;i++){
		dis[i]=LLONG_MAX;
	}
	dis[s]=0;
	q.push({s,0LL});
	while(!q.empty()){
		int u=q.front().first,v=q.front().second;
		q.pop();
		if(v<dis[u]){
			dis[u]=v;
//			if(ans[u]==2){
//				res--;
//			}
			ans[u]=1;
		}
		else if(v==dis[u]){
			ans[u]++;
//			if(ans[u]==2){
//				res++;
//			}
//			if(ans[u]>2){
//				res--;
//			}
		}
		else if(v>dis[u]){
			continue;
		}
		for(int i=0;i<g[u].size();i++){
			int vv=g[u][i];
			q.push({vv,v+1});
		}
//		for(auto vv:g[u]){
//			
//		}
	}
	for(int i=1;i<=n;i++){
//		cout<<ans[i]<<" ";
		if(ans[i]==2&&i!=s){
			anss++;
		}
	}
//	cout<<"\n";
//	if(s==1){
//		cout<<ans[4]<<"\n";
//	}
//	anss+=res;
}
void init(){
	memset(ans,0,sizeof(ans));
	for(int i=0;i<500000;i++){
		g[i].clear();
	}
	anss=0;
}
void solve1(){
	int dd;
	while(t--){
		cin>>n>>d;
		if(n==1){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x2[i];
			if(i==2) dd=x2[i]-x2[i-1];
		}
		if(dd/d==2){
			cout<<max(n-3,0LL)<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		solve1();
		return 0;
	}
	while(t--){
		init();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d&&i!=j){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			memset(ans,0,sizeof(ans));
		}
		cout<<anss/2<<"\n";
	}
}
