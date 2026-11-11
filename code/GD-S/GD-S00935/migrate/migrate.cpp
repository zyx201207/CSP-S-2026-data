#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000005],n,d;
vector<int>vt[2000005];
bool bfs(int st,int en){
	vector<bool>vis(n+1);
	vector<int>dis(n+1);
	vector<int>ce(n+1);
	ce[st]=1;
	queue<int>q;q.push(st);vis[st]=1;dis[st]=1;
	bool c=0,f=0;
	while(q.size()){
		int u=q.front();q.pop();
		for(int v:vt[u]){
			if(vis[v]==0){
				vis[v]=1;ce[v]=ce[u]+1;
				q.push(v);
			}
			else if(ce[u]!=ce[v])dis[u]+=dis[v];
		}
	}
	return dis[en]==2;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){
				vt[i].push_back(j);
				vt[j].push_back(i);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt+=bfs(i,j);
		}
	}
	cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
