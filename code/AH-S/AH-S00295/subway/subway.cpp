#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[20005],num[20005];
struct node{
	long long u,w;
}g[20005][501];
long long ans = 1e18;
void dfs(long long st,long long ed,long long val){
	if(st == ed){
		ans = min(ans, val);
		return;
	}
	for(long long i=0;i<num[st];i++){
		dfs(g[st][i].u,ed,val+g[st][i].w);
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long lax,lay;
		for(long long j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			if(j==1){
				lax=x;
				lay=y;
				continue;
			}
			g[lax][num[lax]].u = x;
			g[lax][num[lax]].w = y+lay;
			num[lax]++;
			lax = x;
			lay = y;
		}
	}
	for(long long k=1;k<=q;k++){
		int st,ed;
		cin>>st>>ed;
		dfs(st,ed,0);
		cout<<ans+w[st]+w[ed]<<endl;
		ans = 1e18;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
