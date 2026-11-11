#include <bits/stdc++.h>
using namespace std;
const int maxN=5e5,maxM=3e5;
int n,m,a[maxN+5];
int last[maxM+5],f[maxN+5],g[maxN+5];
int cnt[maxN+5],d[maxN+5],ans[maxM+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		if(i==n)
			f[i]=n+1,g[i]=n+1;
		else
			f[i]=f[i+1],g[i]=g[i+1];
		if(last[a[i]])
			f[i]=i,g[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cnt[i]++;
		d[i]+=cnt[i];
		d[f[i]]-=cnt[i];
		cnt[g[i]]+=cnt[i];
		d[i]+=d[i-1];
		ans[a[i]]+=d[i];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	for(;T;T--) solve();
}

