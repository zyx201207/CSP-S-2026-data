#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e4+5;
int c,t,n;
ll d,a[N];

struct edge {
	ll To,val;
	edge(ll a,ll b) {
		To=a,val=b;
	}
};

struct node {
	ll id,dis;
	bool operator < (const node a) const {
		return dis<a.dis;
	}
};

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d",&n);
		scanf("%lld",&d);
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		vector<edge> e[2*N];
		int u=1,v=2;
		int ans=0;
		while(u<n) {
			if(abs(a[v]-a[u])<=d) {
				e[u].push_back((edge){v,abs(a[v]-a[u])});
				e[v].push_back((edge){u,abs(a[v]-a[u])});
				v++;
			} else u++,v=u+1;
		}
		
		ll dit[N],num[N];
		bool visit[N];
		priority_queue<node> q;
		for(int i=1; i<=n; i++) {
			dit[i]=1e18;
			visit[i]=false;
			num[i]=1;
		}
		dit[1]=0;
		q.push((node){1,0});
		while(!q.empty()) {
			int k=q.top().id;
			q.pop();
			if(visit[k])continue;
			visit[k]=true;
			for(auto i:e[k]) {
				int to=i.To;
				if(dit[to]>dit[k]+i.val) {
					num[to]=num[k]+1;
					dit[to]=dit[k]+i.val;
					q.push(node {to,dit[to]});
				}
			}
		}
		for(int i=1; i<=n; i++)if(num[i]==2)ans++;
		printf("%d\n",ans);
	}
	return 0;
}
