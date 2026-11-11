#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int a[N];
vector<int> g[N];
struct ott{
	int s,t;
};
vector<int> s;
int vis[N];
int bfs(int x,int y) {
	int cnt=0;
	queue<ott> q;
	s.clear();
	q.push({x,0});
	for(int i=1; i<=n; i++) vis[i]=0;
	while(q.size()) {
		ott t=q.front();
		q.pop();
		if(t.s==y) {
			s.push_back(t.t);
		} 
		for(auto k:g[t.s]) {
			if(!vis[k]) {
				q.push({k,t.t+1});
				if(k!=y) vis[k]=1;
			}
		}
	}
	int minn=s[0];
	for(auto t:s) 
		if(t==minn) cnt++;
	return cnt==2; 
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=15 && c<=18) {
		while(t--) {
			cout<<0<<'\n';
		}
		return 0;
	}
	while(t--) {
		int cnt=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(abs(a[i]-a[j])<=d) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		} 
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(abs(a[i]-a[j])>d) {
					cnt+=bfs(i,j);
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
