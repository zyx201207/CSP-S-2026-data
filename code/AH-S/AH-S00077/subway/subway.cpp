#include <bits/stdc++.h>
using namespace std;
int c,m,n,d,q,o,p;
long long int w[500010],a[500][50010],t[510][50010];
vector<vector<int> >  x(510);
long long int xx[510][50010];
long long int ans;
bool vis[510];
void solve(int from,int lstw,long long int fee){
	if(from==p) {
		ans=min(ans,fee+w[p]);
		return;
	}
	for(int i=0; i<int(x[from].size()); i++){
		int way=x[from][i];
		if(way==lstw) continue;
		for(int j=1; j<=a[way][0]; j++){
			int to=a[way][j];
			if(to==from) continue;
			if(to!=p && x[to].size()==1) continue;
			if(vis[to]) continue;
			vis[to]=1;
			solve(to,way,fee+xx[from][way]+xx[to][way]);
			vis[to]=0;
		}
	}

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	int k;
	for(int i=1; i<=n; i++){
		cin>>k;
		a[i][0]=t[i][0]=k;
		for(int j=1; j<=k; j++) cin>>a[i][j]>>t[i][j],x[a[i][j]].push_back(i),xx[a[i][j]][i]=t[i][j];
	} 
	for(int i=1; i<=q; i++){
		cin>>o>>p;
		ans=1e17;
		vis[o]=1;
		solve(o,0,w[o]);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
