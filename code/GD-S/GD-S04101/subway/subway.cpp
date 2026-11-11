#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, t, l, r, z, w[500005];
struct node{
	int x, y;
};
map<int, pair<int, int> >p;
vector<node>v[600005];
queue<int>q;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &t);
	for(int i=1; i<=m; i++) scanf("%lld", &w[i]);
	for(int i=1; i<=n; i++){
		scanf("%lld", &z);
		while(z--){
			scanf("%lld%lld", &l, &r);
			v[m+i].push_back({l, r});
			v[l].push_back({m+i, r});
		}
	}
	while(t--){
		scanf("%lld%lld", &l, &r);
		p.clear();
		p[l]={0, 1};
		q.push(l);
		while(!q.empty()){
			int h=q.front();
			q.pop();
			for(auto g:v[h]){
				if(p[h].first+g.y<p[g.x].first||p[g.x].second!=1){
					p[g.x]={p[h].first+g.y, 1};
					q.push(g.x);
				}
			}
		}
		printf("%lld\n", p[r].first+w[l]+w[r]);
	}
	return 0;
}
