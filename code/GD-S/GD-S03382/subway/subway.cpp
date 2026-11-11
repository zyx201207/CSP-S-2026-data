#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=550;
const int M=5e5+10;
int tjl[M];
int chongfu[25]; 
int ans=1e7+10;
int e[N][M];
int tot=0;
void bfs(int q,int z){
	for(int i=1;i<=n;i++){
		if(e[i][q]==-1) continue;
		if(e[i][z]!=-1) {
			ans=min(ans,tot+e[i][z]+e[i][q]);
			break;
}
		for(int j=1;j<=m;j++){
			if(q==j) continue;
			if(chongfu[j]<=1) continue;
			tot+=e[i][q]+e[i][j];
			bfs(j,z);
			tot=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tjl[i];
	}
	memset(e,-1,sizeof e);
	memset(chongfu,0,sizeof chongfu);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int u,t;
			cin>>u>>t;
			e[i][u]=t;
			chongfu[u]++;
		}
	}
	while(q--){
		tot=0; 
		int l,r;
		cin>>l>>r;
		bfs(l,r);
		cout<<ans+tjl[l]+tjl[r]<<endl;
			}
	return 0;
		}
