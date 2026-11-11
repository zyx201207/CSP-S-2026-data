#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long w[505],a[505][505],t[505][505],x[100005],y[100005],vis[505][505],mp[505][505];
long long c,n,m,d,q,T,k;
int dx[4]{0,0,-1,1},dy[4]{1,-1,0,0};
struct node{
	int z,r;
};
int bfs(int f,int g){
	queue<node>q;
	q.push({f,g});
	while(!q.empty()){
		node x=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int f1=f+dx[i],g1=g+dy[i];
			if(vis[f1][g1]>=1&&vis[f1][g1]<=n && vis[f1][g1]>=0 &&mp[f1][g1]==0){
				q.push({f1,g1});
				mp[f1][g1]==1;
			}
			//cout<<f1<<' '<<g1<<' ';
			return T=t[f1][g1]+t[g1][g1];
			return f1,g1;
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
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k;j++){
			int f,g;
			f=a[i][j];
			g=a[i][j+1];
			vis[f][g]=t[f][g];
			vis[g][f]=t[g][f];
			if(j+2<=k){
				g=a[i][j+2];
				vis[f][g]=t[f][g];
				vis[g][f]=t[g][f];
			}
		}
	}

	for(int i=1;i<=q;i++){
		T=0;
		cin>>x[i]>>y[i];
		bfs(x[i],x[i]);
		T+=w[x[i]]+t[x[i]][x[i]]+w[y[i]]+t[x[i]][y[i]];
		cout<<T;
	}
	return 0;
}
