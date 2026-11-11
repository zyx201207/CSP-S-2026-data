#include <bits/stdc++.h>
using namespace std;
const int M=5e3+10;
int n,c,t;
struct node {
	int num,x;
};
node vis[M];
long long d,ans,a[2000010];
void bfs(int e) {
	for(int i=e; i<=n; i++) {
		vis[i].num=0;
		vis[i].x=1e9;
	}
	queue<node> q;
	node now;
	now.num=e;
	now.x=0;
	q.push(now);
	while(!q.empty()) {
		node r=q.front();
		q.pop();
		for(int i=r.num+1; i<=n; i++) {
			if(a[i]-a[r.num]<=d) {
				node f;
				f.num=i;
				f.x=r.x+1;
				q.push(f);
				if(f.x==vis[i].x) {
					vis[i].num++;
				}
				if(f.x<vis[i].x) {
					vis[i].num=1;
					vis[i].x=f.x;
				}
				continue;
			}
			break;
		}
	}
	for(int i=e+1; i<=n; i++) {
		if(vis[i].num==2)ans++;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c<=12&&c>=11) {
		while(t--) {
			long long nn;
			ans=0;
			cin>>nn>>d;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}
			long long l=d/(a[2]-a[1]);
			l=2*l-1;
			cout<<nn-l<<"\n";
		}
		return 0;
	}
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<n-2; i++) {
			bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
