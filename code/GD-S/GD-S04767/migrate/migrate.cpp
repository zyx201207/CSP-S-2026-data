#include<bits/stdc++.h>
using namespace std;
int c,T;
int a[10009],n,ans,d;
int dist[10009],sam[10009];
void dfs(int u,int l) {
	if(l==dist[u]) {
		sam[u]++;
	}
	if(l<dist[u]) {
		sam[u]=1;
		dist[u]=l;
	}
	int ff=0;
	for(int i=1; i<=n-u; i++) {
		ff=a[u+i]-a[u];
		if(ff<=d) {
			dfs(u+i,l+1);
		} else {
			break;
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}

		for(int lp=1; lp<=n; lp++) {
			memset(dist,0x3f,sizeof(dist));
			memset(sam,0x3f,sizeof(sam));
			dfs(lp,0);
			for(int i=1; i<=n; i++) {
				if(sam[i]==2) {
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
