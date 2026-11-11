#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sx,gy;
const int M=5e5+5;
long long w[M],k[50005][505],t[50005][505];
long long sum=0,ans=1e18;
void dfs(int x,int y,int i){
	if(x==gy){
		sum+=t[i][y];
		ans=min(ans,sum);
		return ;
	}
	sum+=t[i][x];
	for(int j=1;j<=n;j++){
		if(j==i){
			if(k[j][x]) {
				dfs(k[j][x],y,j); 
			}
		}
		else {
			if(k[j][x]) {
				sum+=t[j][x];
				dfs(k[j][x],y,j); 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int K;
		cin>>K;
		int tt=0,tk=0,ttt=0,ttk=0;
		for(int j=1;j<=K;j++){
			cin>>tt>>tk;
			t[i][tt]=tk;
			k[i][tt]=ttt;
			k[i][ttt]=tt;
			ttt=tt;
			ttk=tk;
		}
	}
	while(q--){
		cin>>sx>>gy;
		sum=w[sx]+w[gy];
		ans=1e18;
		for(int i=1;i<=n;i++) dfs(sx,gy,1);
		cout<<ans<<"\n";
	}
}
