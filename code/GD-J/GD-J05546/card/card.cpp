#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn],cnt[maxn],n,m;
bool vis[maxn];
void bfs(int x) {
	memset(vis,0,sizeof(vis));
	stack<int> s;
	s.push(a[x]);
	vis[a[x]]=1;
	for(int i=x+1; i<=n; i++) {
		if(vis[a[i]]==1) {
			while(!s.empty()) {
				if(s.top()==a[i])break;
				vis[s.top()]=0;
				s.pop();
			}
		} else {
			s.push(a[i]);
			vis[a[i]]=1;
		}
	}
	while(!s.empty()) {
		int p=s.top();
		cnt[p]++;
		s.pop();
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		bfs(i);
	}
	for(int i=1; i<=m; i++) {
		cout<<cnt[i]<<" ";
	}
	return 0;
}

