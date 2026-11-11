#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[40][110];
int t[40][110];
int ti[1100][400];
int v[4000];
int zz[110];
int tu[110][110];
int c,n,m,d,q;
int dfs(int x,int y){
	for(int i=1;i<=n;i++){
		if(tu[x][i]==y){
			return ti[y][x];
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
	/*
	I think I will AFO;
	I love Lyy but......;
	But no problem,I will wait;
	Even if I miss you now;
	I will miss and love you forever;
	In anywhere,anytime,I always miss you;
	*/
	for(int i=1;i<=n;i++){
		int v[i];
		cin>>v[i];
		for(int j=1;j<=v[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v[i];j++){
			zz[a[i][j]]++;
			ti[a[i][j]][i]=t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v[i]-1;j++){
			tu[a[i][j]][a[i][j+1]]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans=w[x]+w[y];
		ans+=dfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
