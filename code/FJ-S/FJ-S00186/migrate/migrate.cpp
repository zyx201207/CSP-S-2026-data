#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d;
int c,t,n;
ll a[2000011],dis[2000011],f[2000011];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) {
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int ans = 0;
		for(int i=1;i<=n;i++) {
			queue <int> q;
			q.push(i);
			f[i] = 1;
			dis[i] = 0;
			for(int j=i+1;j<=n;j++) {
				dis[j] = 0x3f3f3f3f;
				f[j] = 0;
			}
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (f[u] == 2)
					ans++;
				for(int v=u+1;v<=n;v++) {
					if (a[v] - a[u] > d)
						continue;
					if (dis[u] + 1 > dis[v])
						continue;
					if (dis[u] + 1 == dis[v])
						f[v] += f[u];
					else {
						dis[v] = dis[u] + 1;
						f[v] = f[u];
						q.push(v);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
