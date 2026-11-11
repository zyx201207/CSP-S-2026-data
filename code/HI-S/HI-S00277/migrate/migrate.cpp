#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;

int c,t;
int n,ans;
int len=INT_MAX,ji=0;
long long d,a[maxn];

void dfs(int u,int v,int l) {
	if(u==v) {
		if(l>1) len=min(len,l);
		return;
	}
	for(int i=u+1; i<=v; i++) {
		if(a[i]-a[u]<=d) dfs(i,v,l+1);
	}
}

void dfs1(int u,int v,int l) {
//	cout<<u<<" "<<v<<endl;
	if(u==v) {
		//	cout<<v<<" "<<l<<" "<<len<<endl;
		if(l==len) ji++;
		return;
	}
	for(int i=u+1; i<=v; i++) {
		if(a[i]-a[u]<=d) dfs1(i,v,l+1);
		//	cout<<a[i]-a[u]<<" ";
	}
//	cout<<endl;
}

void solve_n5000() {
	for(int i=n; i>=1; i--) {
		
		for(int j=1; j<=i; j++) {
			len=INT_MAX;
			dfs(j,i,0);
			ji=0;
			//	cout<<len<<" "<<i<<" "<<endl;
			dfs1(j,i,0);
			//	cout<<ji<<endl;
			if(ji==2) {
				ans++;
				break;
			}
		}

	}
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
		}
		if(n<=5000) solve_n5000();
		printf("%d\n",ans);
	}
	return 0;
}
