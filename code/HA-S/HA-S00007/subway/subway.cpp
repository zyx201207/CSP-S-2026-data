#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long  w[500010];
int a[510][500010];
int dy[510][500010];
long long t[510][500010];
int k[510];
long long ans;
struct node{
	int num;
	long long sb;
};
vector<node>v[500010];
int dfs(int x,int y,int fa,int fasb,long long cast){
	if(x==y){
		ans=min(ans,cast);
		return 1;
	}
	for(int i=0;i<v[x].size();i++){
		if(v[x][i].num==fa)continue;
//		luxian:v[x][i].sb
//		jinru:t[v[x][i].sb][dy[v[x][i].sb][x]]//->x
//		chula:t[v[x][i].sb][dy[v[x][i].sb][v[x][i].num]]
		long long tca=cast + t[v[x][i].sb][dy[v[x][i].sb][x]] + t[v[x][i].sb][dy[v[x][i].sb][v[x][i].num]];
		if(fasb==v[x][i].sb){
			tca-=2*t[v[x][i].sb][dy[v[x][i].sb][x]];
		}
		dfs(v[x][i].num,y,x,v[x][i].sb,tca);
	}
	return 1;
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
		for(int j=1;j<=k[i];j++){
			dy[i][a[i][j]]=j;
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int z=1;z<=k[i];z++){
				if(z==j)continue;
				v[a[i][j]].push_back({a[i][z],i});
				v[a[i][z]].push_back({a[i][j],i});
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		dfs(x,y,-1,-1,0);
		cout<<ans<<'\n';
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
