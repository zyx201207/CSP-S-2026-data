#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,e[1999],u[1999],ans,pd[20005];
struct qw{
	int q[101];
	int w[101];
	int x=1;
}v[20001];
void lt(int g,int h){
	v[g].q[v[g].x]=h;
	v[g].w[v[g].x]=e[g]+u[h];
	v[g].x++;
	v[h].q[v[h].x]=g;
	v[h].w[v[h].x]=e[h]+u[g];
	v[h].x++;
}
void Dfs(int zt,int mdd,int t){
	if(pd[zt]){
		return;
	}
	if(zt==mdd){
		ans=min(ans,t);
		return;
	}
	for(int i=1;i<=v[zt].x;i++){
		pd[zt]++;
		Dfs(v[zt].q[i],mdd,t+=v[zt].w[i]);
		pd[zt]--;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>e[i];
	}
	for(int i=1;i<=n;i++){
		int k,b[1999];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>u[j];
		}
		for(int j=1;j<=k;j++){
			for(int o=j+1;j<=k;j++){
				lt(b[j],b[o]);
			}
		}
	}
	for(int i=1,es,se;i<=q;i++){
		ans=1000000000;
		cin>>es>>se;
		Dfs(es,se,0);
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
