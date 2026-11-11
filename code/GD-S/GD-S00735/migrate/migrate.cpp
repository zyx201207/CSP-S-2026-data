#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef long long lld;
lld a[2000100],d[2000100],c[2000100];
vector<int> E[200100];
queue<int> q;

void bfs(int s){
	int u;
	q.push(s);
	d[s] = 1,c[s] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int v : E[u]){
			if(d[v] > d[u]+1){
				d[v] = d[u]+1;
				c[v] = c[u];
				q.push(v);
			}
			else if(d[v] == d[u]+1){
				c[v] += c[u];
			}
		}
	}
}
void solve(){
	int n;
	lld l,ans=0;
	cin>>n>>l;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		E[i].clear();
		d[i] = c[i] = 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			if(i!=j && a[j]-a[i]<=l){
				E[i].push_back(j);
			}
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			d[j] = 1e9;
			c[j] = 0;
		}
		bfs(i);
		for(int j = i+1; j <= n; j++){
			ans += c[j]==2;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int yessssssssssssssssssssssssssssssssssssssssssssssss,T;
	for(cin>>yessssssssssssssssssssssssssssssssssssssssssssssss>>T; T--; solve());
	return 0;
}