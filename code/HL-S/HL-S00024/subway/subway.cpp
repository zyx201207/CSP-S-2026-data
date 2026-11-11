#include<bits/stdc++.h>
using namespace std;
int c,d,q,n,m,cnt=10000000,x,y;
int w[500010];
int k[510];
int vis[51000];
int a[500][500050];
void dfs(int u,int bas){
	if(u==y){
		if(cnt>bas)cnt=bas;
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[u][i]!=0 && vis[i]!=1){
			vis[i]=1;
			dfs(i,bas+a[u][i]);
			vis[i]=0;
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
		int b[3],t[3];
		for(int j=1;j<=k[i];j++){
			cin>>b[j]>>t[j];
		}
		a[b[1]][b[2]]=t[1]+t[2];
	}
	while(q--){
		cin>>x>>y;
		dfs(x,0);
		cnt+=w[x]+w[y];
		cout<<cnt<<endl;
	}
	return 0;
}