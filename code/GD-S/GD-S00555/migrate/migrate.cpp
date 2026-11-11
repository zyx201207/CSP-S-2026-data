#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c;
void solve(){
	int n,d;
	cin>>n>>d;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int> e[n+1];
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d)e[i].push_back(j);
			else break;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		queue<pair<int,int> >q;
		
		q.push({i,0});
		int dis[n+1]={},vis[n+1]={};
		
		while(!q.empty()){
			auto u=q.front();
			q.pop();
			//cout<<u.first;
			for(auto v:e[u.first]){
				if(u.second+1==dis[v])vis[v]++;
				
				if(!vis[v])dis[v]=u.second+1,vis[v]++;
				q.push({v,u.second+1});
			}
		}
		for(int j=i;j<=n;j++)if(vis[j]==2)cnt++;
	}
	cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
