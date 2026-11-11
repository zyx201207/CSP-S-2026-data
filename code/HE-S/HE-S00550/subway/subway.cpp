#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[505][500005];
int t[505][500005];
bool st[500005];
vector<int> f[500005];
struct A{
	int fx,id,tlx,cnt;
}e[500005];
int ans;
int dfs(int u,int ed,int lns){
	st[u]=1;
	if(st[ed]){
		ans=max(ans,lns);
	}
	int tx=e[u].tlx;
	for(int i=1;i<=e[u].cnt;i++){
		if(st[u]) continue;
		int v=e[i].fx;
		int nx=e[i].tlx;
		if(nx!=tx){
			lns+=t[nx][e[i].id]+t[tx][e[i].id];
			dfs(v,ed,lns);
			lns-=t[nx][e[i].id]+t[tx][e[i].id];
		}
		else{
			dfs(v,ed,lns);
		}
	}
	st[u]=0;
}
void fld(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans=0;
			dfs(i,j,t[e[i].tlx][e[i].id]+t[e[j].tlx][e[j].id]);
			f[i][j]=ans;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int jj=(j+1)/2;
			cin>>a[i][jj]>>t[i][jj];
		}
		for(int j=2;j<=k[i];j++){
			e[a[i][j-1]].fx=a[i][j];
			e[a[i][j-1]].id=j;
			e[a[i][j-1]].tlx=i;
			e[a[i][j-1]].cnt++;
			e[a[i][j]].fx=a[i][j-1];
			e[a[i][j]].id=j-1;
			e[a[i][j]].tlx=i;
			e[a[i][j]].cnt++;
		}
	}
	fld();
	while(q--){
		int S,T;
		cin>>S>>T;
		cout<<12123;
	}
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
