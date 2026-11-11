#include<bits/stdc++.h>
using namespace std;
using t64 = long long;
constexpr t64 INF = 1000000000000000000;
struct mx{
	t64 v,cnt;
};
t64 c,t,n,d,ans;
t64 x[5005];
vector<t64> mp[5005];
mx r[5005];
bool vis[5005];
void dfs(t64 s){
	for(t64 i=1;i<=5004;i++){
		vis[i] = 0;
		r[i].cnt = 0;
		r[i].v = INF;
	}
	stack<pair<t64,t64> >sk;
	sk.push({s,0});
	vis[s]=1;
	while(!sk.empty()){
		pair<t64,t64> tmp=sk.top();
		sk.pop();
		t64 u = tmp.first;
		t64 length = tmp.second;
		if(length<r[u].v){
			r[u].cnt=1;
			r[u].v=length;
		}
		else if(length==r[u].v){
			r[u].cnt++;
			continue;
		}
		else continue;
		for(t64 v:mp[u]){
			if(!vis[v]){
				vis[v] = 1;
				sk.push({v,length+1});
				vis[v] = 0;
			}
		}
	}
	vis[s]=0;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n>>d;
		for(int i=1;i<=n;i++)cin >> x[i];
		for(int i=1;i<=n;i++)mp[i].clear();
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				if(x[v]-x[u]<=d){
					mp[u].push_back(v); 
					mp[v].push_back(u);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i);
			for(int j=1;j<=n;j++){
				if(r[j].cnt == 2)ans++;
			}
		}
		cout << ans / 2 <<'\n';
	}
	return 0;
} 
