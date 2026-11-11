#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
struct node{
	int id,t;
	bool v;
};
vector <node> a[N];
int c,n,m,d,q;
int w[M],k[N],xx[M][23],xs[M],xt[M][23];
int st,ed;
node u;
long long cnt=1e15;
void dfs(int i,long long s){
	if (s>=cnt) return;
	if (i==ed){
		cnt=min(s,cnt);
		return;
	}
	for (int x=1;x<=xs[i];x++){
		for (int y=0;y<k[xx[i][x]];y++){
			if (!a[xx[i][x]][y].v && a[xx[i][x]][y].id!=i){
				a[xx[i][x]][y].v=1;
				dfs(a[xx[i][x]][y].id,s+xt[i][x]+a[xx[i][x]][y].t);
				a[xx[i][x]][y].v=0;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>u.id>>u.t;
			a[i].push_back(u);
			xx[u.id][++xs[u.id]]=i;
			xt[u.id][xs[u.id]]=u.t;
		}
	}
	for (int i=1;i<=q;i++){
		cnt=1e15;
		cin>>st>>ed;
		dfs(st,0);
		cout<<cnt+w[st]+w[ed]<<"\n";
	}
	return 0;
} 
