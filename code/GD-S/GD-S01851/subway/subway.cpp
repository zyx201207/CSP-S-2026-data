#include<bits/stdc++.h>
#include<vector>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010],b[510],x,y,s,l;
bool f[500010],g[510];
vector<int> e[510],r[500010];
void dfs(int x){
	if(x==y) l=min(l,s);
	int lr=r[x].size();
	for(int i=0;i<lr;i++){
		if(!g[i])
		for(int j:e[i]){
			g[i]=1;
			l+=t[i][x];
			int nx=j;
			if(!f[nx]){
				l+=t[i][nx];
				f[nx]=1;
				dfs(nx);
				f[nx]=0;
				l-=t[i][nx];
			}
			l-=t[i][x];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];//√ª ≤√¥”√ 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>a[i][1]>>t[i][1];
		b[i]=t[i][1];
		for(int j=2;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			r[a[i][j]].push_back(i);
			e[i].push_back(a[i][j]);
			b[i]=min(t[i][j],b[i]);
		}
	}
	while(q--){
		cin>>x>>y;
		if(c>=12&&c<=19){
			cout<<w[x]+w[y]+b[1]*2;
		}
		s=0;
		l=99999999;
		f[x]=1;
		dfs(x);
	}
	return 0;
} 
