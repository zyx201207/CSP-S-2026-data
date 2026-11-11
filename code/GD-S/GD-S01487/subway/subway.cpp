#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,pair<ll,ll>>

struct node {ll v,xl;};
ll bh,n,m,q,maxn,w[1005],d[1005][1005],st,ed,a[1005],t[1005],s[1005][1005],ans,jj[1005][1005];
vector <node> zd[1005];

void dij() {
	memset(d,63,sizeof d);
	priority_queue <pll,vector <pll>,greater <pll>> q;
	for (int i = 1;i <= m;i++) 
		if (s[st][i]) {
			q.push({0,{st,i}});
			d[st][i] = s[st][i];
		}
	while (!q.empty()) {
		int dxl = q.top().second.second,x = q.top().second.first;
		q.pop();
		for (node i:zd[x]) {
			int y = i.v,nxl = i.xl;
			if (dxl == nxl) {
				if (d[x][dxl] < d[y][nxl]) {
					d[y][nxl] = d[x][dxl];
					q.push({d[y][nxl],{y,nxl}});
				}
			}
			else {
				if (d[x][dxl] + s[x][dxl] + s[x][nxl] < d[y][nxl]) {
					d[y][nxl] = d[x][dxl] + s[x][dxl] + s[x][nxl];
					q.push({d[y][nxl],{y,nxl}});
				}
			}
		}
	}
}

int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&bh,&m,&n,&maxn,&q);
	for (ll i = 1;i <= n;i++) scanf("%lld",&w[i]);
	for (ll i = 1,k;i <= m;i++) {
		scanf("%lld",&k);
		for (ll j = 1;j <= k;j++) scanf("%lld%lld",&a[j],&t[j]);
		for (ll j = 1;j <= k;j++) {
			if (j == 1) zd[a[j]].push_back({a[2],i});
			else if (j == k) zd[a[j]].push_back({a[k - 1],i});
			else {
				zd[a[j]].push_back({a[j + 1],i});
				zd[a[j]].push_back({a[j - 1],i});
			}
			s[a[j]][i] = t[j];
		}
	}
	while (q--) {
		scanf("%lld%lld",&st,&ed);
		if (jj[st][ed] || jj[ed][st]) {
			printf("%lld\n",jj[st][ed]);
			continue;
		}
		dij();
		ans = 1e9;
		for (int i = 1;i <= m;i++) ans = min(ans,d[ed][i] + s[ed][i]);
		printf("%lld\n",ans + w[st] + w[ed]);
		jj[st][ed] = jj[ed][st] = ans + w[st] + w[ed];
	}
	return 0;
}
